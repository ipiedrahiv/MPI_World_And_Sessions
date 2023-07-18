#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	MPI_Session session;
	int rc = MPI_Session_init(MPI_INFO_NULL, MPI_ERRORS_RETURN, &session);
	if (rc != MPI_SUCCESS) {
		printf("Session_init failed!!\n");
		return -1;
	}

	// Start group and comm
	MPI_Group group = MPI_GROUP_NULL;
	MPI_Comm comm = MPI_COMM_NULL;
	char pset_name[] = "mpi://WORLD";
	rc = MPI_Group_from_session_pset(session, pset_name, &group);
	rc = MPI_Comm_create_from_group(group, "example3.pingpong", MPI_INFO_NULL, MPI_ERRORS_RETURN, &comm);

	// Get rank and size
	int rank, size;
	MPI_Comm_rank(comm, &rank);
	MPI_Comm_size(comm, &size);

	// Check that there are at least two processes
	if (size != 2) {
		printf("World size must be two!!");
		return -1;
	}

	int ping_pong_count = 0;
	int ping_pong_limit = 10;

	while (ping_pong_count < ping_pong_limit) {
		if (rank == 0) {
			++ping_pong_count;
			MPI_Send(&ping_pong_count, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
			printf("0 sent and incremented ping_pong_count %d to 1\n", ping_pong_count);
		} else if (rank == 1) {
			MPI_Recv(&ping_pong_count, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("1 recieved ping_pong_count %d from 0\n", ping_pong_count);
		
		}
	}
	
	MPI_Finalize();
	return 0;
}


		
		
	
