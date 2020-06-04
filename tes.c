#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
//#difine 

int main(int argc, char *argv[]){

MPI_Init(NULL,NULL);
int rank;

 
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
if(rank==0){
int x =10;
MPI_Send(&x,1,MPI_INT,1,1,MPI_COMM_WORLD);//MPI_Send(data, count, datatype, i, 0, communicator);
}
else
{
int y;
MPI_Recv(&y, 1,MPI_INT,0,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
printf("RECEIVED DATA:%d\n",y);
}
MPI_Finalize();
return 0;

}
