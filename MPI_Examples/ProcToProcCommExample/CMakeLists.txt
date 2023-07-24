# CMakeLists.txt for ProcToProcCommExample

add_mpi_executable(ProcToProcCommExample_world world.c)
add_mpi_executable(ProcToProcCommExample_sessions sessions.c)
