set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(TestBoost
    3rdBoost/TestBoost.cpp)
target_include_directories(TestBoost PUBLIC
    ${CMAKE_SOURCE_DIR}/include/3rdBoost
    ${CMAKE_SOURCE_DIR}/include/common)

add_library(TestJson
    3rdJson/TestJson.cpp)
target_include_directories(TestJson PUBLIC
    ${CMAKE_SOURCE_DIR}/opensource/nlohmann
    ${CMAKE_SOURCE_DIR}/include/3rdJson)

include_directories(${CMAKE_SOURCE_DIR}/include
                    ${CMAKE_SOURCE_DIR}/opensource/spdlog/include
                    ${CMAKE_SOURCE_DIR}/opensource/Boost
                    ${CMAKE_SOURCE_DIR}/opensource/nlohmann)

add_executable(main main.cpp)
target_link_libraries(main TestBoost TestJson)