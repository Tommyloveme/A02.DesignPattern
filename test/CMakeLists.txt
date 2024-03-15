# 指定可执行文件的生成位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 设置包含的头文件路径
set(INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/include")
file(GLOB_RECURSE HEADERS "${INCLUDE_DIRS}/*.h" "${INCLUDE_DIRS}/*.hpp")
include_directories(${INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/opensource/gtest/include
                    ${CMAKE_SOURCE_DIR}/opensource/spdlog/include
                    ${CMAKE_SOURCE_DIR}/opensource/Boost
                    ${CMAKE_SOURCE_DIR}/opensource/nlohmann)

# 指定静态链接库文件目录
link_directories(
    ${PROJECT_SOURCE_DIR}/opensource/gtest/lib
    ${PROJECT_SOURCE_DIR}/lib)

# 设置源文件目录
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/test")
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")
add_executable(test ${SOURCES})

target_link_libraries(test gtest gtest_main DesignPattern TestBoost TestJson)