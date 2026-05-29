cmake_minimum_required(VERSION 3.16)

project(particle_sim_cpp VERSION 0.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(PkgConfig REQUIRED)
pkg_check_modules(RAYLIB REQUIRED raylib)

add_executable(particle_sim
    src/main.cpp
    src/particle.cpp
    src/random.cpp
    src/display.cpp
)

target_include_directories(particle_sim PRIVATE
    include
    ${RAYLIB_INCLUDE_DIRS}
)

target_link_directories(particle_sim PRIVATE
    ${RAYLIB_LIBRARY_DIRS}
)

target_link_libraries(particle_sim PRIVATE
    ${RAYLIB_LIBRARIES}
)

target_compile_options(particle_sim PRIVATE
    ${RAYLIB_CFLAGS_OTHER}
)