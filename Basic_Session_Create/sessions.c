#include <mpi.h>
#include <stdio.h>


int main(int argc, char *argv[]){
	MPI_Session lib_shandle = MPI_SESSION_NULL;
	
	MPI_Info sinfo = MPI_INFO_NULL;
	MPI_Info_create(&sinfo);

	int rc = MPI_Session_init(MPI_INFO_NULL, MPI_ERRORS_RETURN, &lib_shandle);
		
	printf("rc = %d\n", rc);

	MPI_Session_finalize(&lib_shandle);

	return(0);
}

