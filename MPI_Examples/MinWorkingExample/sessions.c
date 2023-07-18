#include <mpi.h>
#include <stdio.h>


int main(int argc, char *argv[]){
	MPI_Session session = MPI_SESSION_NULL;
	int rc = MPI_Session_init(MPI_INFO_NULL, MPI_ERRORS_RETURN, &session);
	
	MPI_Comm comm = MPI_COMM_NULL;
	MPI_Group group = MPI_GROUP_NULL;
	const char pset_name[] = "mpi://WORLD";

	rc = MPI_Group_from_session_pset(session, pset_name, &group);
	rc = MPI_Comm_create_from_group(group, "example.example", MPI_INFO_NULL, MPI_ERRORS_RETURN, &comm);	
	
	if (rc == MPI_SUCCESS){	
		int rank, size;
		MPI_Comm_rank(comm, &rank);
		MPI_Comm_size(comm, &size);
		printf("Rank %d out of %d\n", rank, size);
	}	

	MPI_Group_free(&group);

	MPI_Session_finalize(&session);
	

	return(0);
}

