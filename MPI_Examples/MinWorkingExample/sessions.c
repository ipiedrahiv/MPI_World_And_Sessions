#include <mpi.h>
#include <stdio.h>

static MPI_Session lib_shandle = MPI_SESSION_NULL;

int main(int argc, char *argv[]){
	const char mt_key[] = "thread_level";
	const char mt_value[] = "MPI_THREAD_MULTIPLE";

	MPI_Info sinfo = MPI_INFO_NULL;
	MPI_Info_create(&sinfo);
	MPI_Info_set(sinfo ,mt_key, mt_value);

	int rc = MPI_Session_init(sinfo, MPI_ERRORS_RETURN, &lib_shandle);
		
	printf("rc = %d\n", rc);

	MPI_Session_finalize(&lib_shandle);

	return(0);
}

