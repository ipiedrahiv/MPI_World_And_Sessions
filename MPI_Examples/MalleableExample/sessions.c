#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	MPI_Session session;
	
	
	int rc = MPI_Session_init(MPI_INFO_NULL, MPI_ERRORS_RETURN, &session);

	if (rc != MPI_SUCCESS) {
		printf("Session_Init failed!\n");
		return -1;
	}

	MPI_Comm comm = MPI_COMM_NULL;

	int i, n;
	n = 3;

	for (i = 0; i<n; ++i) {
		change_comm(&session, &comm, i);

		if (comm != MPI_COMM_NULL) {
			//do_work(&comm, i);
			MPI_Comm_free(&comm);
		}
	}

	MPI_Sessions_finalize(&session);
	return 0;
}

void change_comm(const MPI_Session* session, const MPI_Comm* comm, int i) {
	MPI_Group group = MPI_GROUP_NULL;
	get_group(&session, &group, i);

	int rc = MPI_Comm_create_from_group(group, "example_name.malleability", MPI_INFO_NULL, MPI_ERRORS_RETURN, comm);

	if (rc != MPI_SUCCESS) {
                printf("Comm_create_from_group failed!\n");
                return;
        }

	if (*comm != MPI_COMM_NULL) {
		printf("Communicator created correctly!\n");

		int rank, size;
		MPI_Comm_size(*comm, &size);
		MPI_Comm_rank(*comm, &rank);

		printf("Process %d/%d  - Iteration: %d\n", rank, size-1, i);
	}else{
		printf("Process without identification is not in comm\n");
	}

	MPI_Group_free(&group);
}

void get_group(const MPI_Session* session, MPI_Group* group, int i) {
	const char* group_pset[3] = {"mpi://WORLD", "user://ELF_DEFINED1", "user://EMPTY"};
	const char* pset_name = group_pset[i];
	int rc = MPI_Group_from_session_pset(*session, pset_name, &group);
}
