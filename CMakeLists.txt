cmake_minimum_required(VERSION 3.20)

project(yu_toy_browser CXX)
set(CMAKE_CXX_STANDARD 14) # C++14...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

file(GLOB_RECURSE SOURCE_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*.h" "${PROJECT_SOURCE_DIR}/src/*.cpp")
message(${SOURCE_LIST})
add_executable(yu_toy_browser ${SOURCE_LIST})
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(LibXml2 REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
include(FetchContent)
FetchContent_Declare(
        freetype
        URL https://download.savannah.gnu.org/releases/freetype/freetype-2.10.0.tar.gz
)
FetchContent_MakeAvailable(freetype)
target_link_libraries(yu_toy_browser
        OpenGL::GL
        GLEW::glew
        LibXml2::LibXml2
        glfw
        glm::glm
        freetype
        )
