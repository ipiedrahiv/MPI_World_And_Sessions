project (ExamplesMPI)

# Require MPI for this project:
find_package (MPI_REQUIRED) # This is the FindMPI module

add_executable (sessions_MinWorkingExample MinWorkingExample/sessions.c)
add_executable (world_MinWorkingExample MinWorkingExample/world.c)

target_include_directories (sessions_MinWorkingExample PRIVATE ${MPI_C_INCLUDE_PATH})
target_compile_options (sessions_MinWorkingExample PRIVATE ${MPI_C_COMPILE_FLAGS})
target_link_libraries (sessions_MinWorkingExample ${MPI_C_LIBRARIES} ${MPI_C_LINK_FLAGS})

add_custom_target(distclean COMMAND -rf CMakeCache.txt CMakeFiles Makefile cmake_install.cmake)
