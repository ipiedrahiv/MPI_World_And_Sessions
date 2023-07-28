cmake_minimum_required(VERSION 3.5)

project(MPI_Examples)

# Find MPI package
find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})

# Function to add an MPI executable and link it with MPI libraries
function(add_mpi_executable target)
    add_executable(${target} ${ARGN})
    target_link_libraries(${target} ${MPI_C_LIBRARIES})
endfunction()

# Add subdirectories for each example
add_subdirectory(MinWorkingExample)
add_subdirectory(PingPongExample)
add_subdirectory(ProcToProcCommExample)
add_subdirectory(MalleableExample)
