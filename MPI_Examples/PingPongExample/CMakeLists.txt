# CMakeLists.txt for PingPongExample

add_mpi_executable(PingPongExample_world world.c)
add_mpi_executable(PingPongExample_sessions sessions.c)
