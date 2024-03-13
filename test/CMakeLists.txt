# 指定可执行文件的生成位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

aux_source_directory(. TEST_LIST)

# 指定.h头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include
                    ${PROJECT_SOURCE_DIR}/include/3rdBoost
                    ${PROJECT_SOURCE_DIR}/opensource/gtest/include
                    ${CMAKE_SOURCE_DIR}/opensource/spdlog/include
                    ${CMAKE_SOURCE_DIR}/opensource/Boost)

# 指定静态链接库文件目录
link_directories(
    ${PROJECT_SOURCE_DIR}/opensource/gtest/lib
    ${PROJECT_SOURCE_DIR}/lib)

add_executable(test ${TEST_LIST})

target_link_libraries(test gtest gtest_main DesignPattern TestBoost)