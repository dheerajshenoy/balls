cmake_minimum_required(VERSION 3.16)
project(balls VERSION 1.0 LANGUAGES CXX)

find_package(SDL2 REQUIRED)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++20")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Balls.cpp
    src/Circle.cpp
)

include_directories(${SDL2_INCLUDE_DIRS})
# target_include_directories(${PROJECT_NAME} PRIVATE)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${SDL2_LIBRARIES})


# install(TARGETS ${PROJECT_NAME}
#         RUNTIME DESTINATION bin)
#
# #Install .desktop file
# install(FILES ${CMAKE_SOURCE_DIR}/imgv.desktop DESTINATION share/applications)
#
# # Install icons
# install(DIRECTORY ${CMAKE_SOURCE_DIR}/icons/ DESTINATION share/icons/hicolor)
