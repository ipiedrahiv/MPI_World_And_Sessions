# MPI_World_And_Sessions

## Message Passing

- The point of MPI is to send pessages from process to process.
- The message is composed of a triplet at both ends: a pointer to a memory buffer, a count and a type.
	- Memory buffer: 
		- A conitguous block of memory used for storing data.
		- There is a send buffer and a recieve buffer, the recieve buffer may be larger than the send buffer.
		- A buffer is usually an array or a pointer to a region of memory.
	- Count:
		- The number of data elements being sent or recieved.
		- Usually an integer parameter.
	- Type:
		- Send and recieve types can be non-matching.
- The envelope is also composed of a triplet: Rank, tag and communication group.
- There are blocking and nonblocking forms of sending and recieving. The non-blocking ones are easier to use correctly. Blocking sends and recieves need to be carefuly orderen in order to get correct results.
- Blocking sends and recieves might result in a hang, in which one or more process are waiting on an event that will never occour.

## The Send and Recieve Commands

- `MPI_Send(void *data, int count, MPI_Datatype datatype, int destination, int tag, MPI_COMM comm)`
- `MPI_Recv(void *data, int count, MPI_Datatype datatype, int source, int tag, MPI_COMM comm, MPI_Status *status)`




