#include <mpi.h>
#include <stdio.h>


int main(int argc, char *argv[]){
	// MPI handle for the session
	MPI_Session session = MPI_SESSION_NULL;
	
	// Initialize session
	int rc = MPI_Session_init(MPI_INFO_NULL, MPI_ERRORS_RETURN, &session);
		
	printf("rc = %d\n", rc);

	MPI_Session_finalize(&session);

	return(0);
}

