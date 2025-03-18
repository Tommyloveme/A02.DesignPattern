# 指定可执行文件的生成位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 自定义函数用于递归获取目录
function(get_directories result dir)
    file(GLOB children RELATIVE ${dir} ${dir}/*)
    set(dirlist "")
    foreach(child ${children})
        if(IS_DIRECTORY ${dir}/${child})
            list(APPEND dirlist ${dir}/${child})
            get_directories(subdir ${dir}/${child}) # 递归调用
            list(APPEND dirlist ${subdir}) # 将子目录也添加到列表中
        endif()
    endforeach()
    set(${result} ${dirlist} PARENT_SCOPE)
endfunction()

# 递归获取目录
get_directories(INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/include)

include_directories(${INCLUDE_DIRS}
                    ${CMAKE_SOURCE_DIR}/include)

include_directories(
    ${PROJECT_SOURCE_DIR}/opensource/gtest/include
    ${PROJECT_SOURCE_DIR}/opensource/gmock/include
    ${CMAKE_SOURCE_DIR}/opensource/spdlog/include
    ${CMAKE_SOURCE_DIR}/opensource/Boost
    ${CMAKE_SOURCE_DIR}/opensource/nlohmann
)

# 指定静态链接库文件目录
link_directories(
    ${PROJECT_SOURCE_DIR}/opensource/gtest/lib
    ${PROJECT_SOURCE_DIR}/opensource/gmock/lib
    ${PROJECT_SOURCE_DIR}/lib)

# 设置源文件目录
# set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/test")
# set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/test/DesignPattern")
# file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")

# 手动选择要编译的cpp文件
set(test_files ${CMAKE_SOURCE_DIR}/test/stl/TestPtr.cpp)

add_executable(test ${test_files})
# message(STATUS "Value of INCLUDE_DIRS: ${INCLUDE_DIRS}")
# message(STATUS "Value of SOURCES: ${SOURCES}")

target_link_libraries(test gtest gmock gtest_main TestBoost TestJson Data)