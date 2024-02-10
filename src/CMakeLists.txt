aux_source_directory(. SRC_LIST)

#windows系统动态库生成lib文件命令
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")
add_library(DesignPattern
    DesignPattern.cpp
    creational/Creational.cpp)
target_include_directories(DesignPattern PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/creational
    ${CMAKE_SOURCE_DIR}/opensource/spdlog/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(main main.cpp)
target_link_libraries(main DesignPattern)