cmake_minimum_required(VERSION 3.10)
project(ParticleSimulator)

set(CMAKE_CXX_STANDARD 17)

# Add source files
add_executable(ParticleSimulator 
    src/main.cpp 
    src/particle/Particle.cpp
    src/grid/GridManager.cpp
)

# Include header file directories
include_directories(src)

# Link SFML libraries
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(ParticleSimulator sfml-graphics sfml-window sfml-system)


