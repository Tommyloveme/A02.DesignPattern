set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")
add_library(DesignPattern
    DesignPattern.cpp
    creational/Creational.cpp)
target_include_directories(DesignPattern PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/creational
    ${CMAKE_SOURCE_DIR}/opensource/spdlog/include)

# add_library(TestBoost
#     test/TestBoost.cpp)
# target_include_directories(TestBoost PUBLIC
#     ${CMAKE_SOURCE_DIR}/include/test
#     ${CMAKE_SOURCE_DIR}/opensource/Boost)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
include_directories(${CMAKE_SOURCE_DIR}/include
                    ${CMAKE_SOURCE_DIR}/include/test
                    ${CMAKE_SOURCE_DIR}/opensource/spdlog/include
                    ${CMAKE_SOURCE_DIR}/opensource/Boost)
add_executable(main main.cpp)
target_link_libraries(main DesignPattern)