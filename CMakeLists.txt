# CMakeList.txt : CMake project for LiliumEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)          # request C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON) # require it
set(CMAKE_CXX_EXTENSIONS OFF)       # optional: disable compiler-specific extensions

project (LiliumEngine)

# Helper function to disable RTTI and exceptions

function(disable_rtti_and_exceptions target)
    if (MSVC)
        target_compile_options(${target} PRIVATE /GR- /EHs-c-)
        target_compile_definitions(${target} PRIVATE _HAS_EXCEPTIONS=0)
    else()
        target_compile_options(${target} PRIVATE -fno-rtti -fno-exceptions)
    endif()
endfunction()

find_package(glm CONFIG REQUIRED)
find_package(SDL3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(imguizmo CONFIG REQUIRED)

# Add source to this project's executable.
add_executable (${PROJECT_NAME} LiliumEngine.cpp)

# Disabling RTTI and exceptions
disable_rtti_and_exceptions(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)
target_link_libraries(${PROJECT_NAME} PRIVATE imguizmo::imguizmo)

# For generating the release, we need to copy assets folder to build folder
file(COPY ${CMAKE_SOURCE_DIR}/Data DESTINATION ${CMAKE_BINARY_DIR})

# Setting custom working directory within root's 'launch.vs.json and copying within .vs folder
configure_file(
    "${CMAKE_SOURCE_DIR}/launch.vs.json"
    "${CMAKE_SOURCE_DIR}/.vs/launch.vs.json"
    COPYONLY
)