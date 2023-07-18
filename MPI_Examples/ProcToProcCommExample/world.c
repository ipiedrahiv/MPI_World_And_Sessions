#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	// Initialize MPI environment
	MPI_Init(NULL, NULL);

	// Get rank and size
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

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

	MPI_Finalize();
} 
