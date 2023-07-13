#include <mpi.h>
#include <stdio.h>


int main(int argc, char *argv[]){
	MPI_Session lib_shandle = MPI_SESSION_NULL;
	MPI_Comm lib_comm = MPI_COMM_NULL;
	
	MPI_Info sinfo = MPI_INFO_NULL;
	MPI_Info_create(&sinfo);

	int rc = MPI_Session_init(MPI_INFO_NULL, MPI_ERRORS_RETURN, &lib_shandle);

	MPI_Group wgroup = MPI_GROUP_NULL;
	const char pset_name[] = "mpi://WORLD";

	rc = MPI_Group_from_session_pset(lib_shandle, pset_name, &wgroup);
	rc = MPI_Comm_create_from_group(wgroup, "example", MPI_INFO_NULL, MPI_ERRORS_RETURN, &lib_comm);	
	
	int rank, size;
	MPI_Comm_rank(wgroup, &rank);
	MPI_Comm_size(wgroup, &size);
	printf("Rank %d out of %d\n", rank, size);
	
	MPI_Group_free(&wgroup);

	MPI_Session_finalize(&lib_shandle);

	return(0);
}

