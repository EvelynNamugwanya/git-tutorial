  
//making this non blocking collective communication

//one process is sending to all processes in the communicator- this is ineffiencient  because because there are only is only one network link of communication from process to other processess.you can make this faster by introducing double links of communication at each mpi stage

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
MPI_Request request = MPI_REQUEST_NULL;

void MPI_Ibcast(void* data, int count, MPI_Datatype datatype, int root,
              MPI_Comm communicator,MPI_Request request) {
  int world_rank;
  MPI_Comm_rank(communicator, &world_rank);
  int world_size;
  MPI_Comm_size(communicator, &world_size);

  if (world_rank == root) {
    // If we are the root process, send our data to everyone
    int i;
    for (i = 0; i < world_size; i++) {
      if (i != world_rank) {
        MPI_Send(data, count, datatype, i, 0, communicator);
      }
    }
  } else {
    // If we are a receiver process, receive the data from the root
    MPI_Recv(data, count, datatype, root, 0, communicator, MPI_STATUS_IGNORE);
  }
}

int main(int argc, char** argv) {
  MPI_Init(NULL, NULL);
MPI_Request request = MPI_REQUEST_NULL;
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  int data;
  if (world_rank == 0) {
    data = 100;
    printf("Process 0 broadcasting data %d\n", data);
    MPI_Ibcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);
  } else {
    MPI_Ibcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received data %d from root process\n", world_rank, data);
  }

  MPI_Finalize();
}
