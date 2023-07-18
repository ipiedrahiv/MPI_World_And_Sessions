#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	// Declare the session and initialize it
	MPI_Session session;
	int rc = MPI_Session_init(MPI_INFO_NULL, MPI_ERRORS_RETURN, &session);
	if (rc != MPI_SUCCESS) {
		printf("Session_init failed!!\n");
		return -1;
	}

	// Declare group
	MPI_Group group = MPI_GROUP_NULL;

	// Instanciate pset_name
	char pset_name[] = "mpi://WORLD";

	// Declare communicator
	MPI_Comm comm = MPI_COMM_NULL;

	// Create group from session and communicator from group
	rc = MPI_Group_from_session_pset(session, pset_name, &group);
	rc = MPI_Comm_create_from_group(group, "example2.p2pComm", MPI_INFO_NULL, MPI_ERRORS_RETURN, &comm);	

	// Get rank and size
	int rank, size;
	MPI_Comm_rank(comm, &rank);
	MPI_Comm_size(comm, &size);

	// Assuming there are at least two processes
	if (size < 2) {
		printf("World size must be at least two!!/n");
		MPI_Abort(MPI_COMM_WORLD, 1);
	}

	int number;
	if (rank == 0) {
		// Set number to -1 and sent it to process 1
		number = -1;
		MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	} else if (rank == 1) {
		MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Process 1 recieved number %d from process 0.\n", number);
	}

	MPI_Group_free(&group);
	MPI_Session_finalize(&session);

	return 0;
} 
