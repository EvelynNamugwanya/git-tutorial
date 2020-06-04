#include <stdio.h> 
#include <stdlib.h> 
//#include<mpi.h>
#include <string.h>
#include <mpi.h>


int main(int argc, char*argv[]){
//MPI_Init(&argc,&argc);
MPI_Init(&argc, &argv);


//creating the cartesian topology
int p,myrank;
MPI_Comm_size(MPI_COMM_WORLD,&p);
MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
//MPI_Comm_rank(MPI_COMM_WORLD,&p);
int dims[3]={5,5,5};
MPI_Dims_create(p,3,dims);
int periods[3]={1,1,1};
MPI_Comm topocomm;
MPI_Cart_create(MPI_COMM_WORLD,3,dims,periods,0,&topocomm);//create anew communicator topocomm

int MPI_Cartdim_get(MPI_Comm topocomm, int *ndims);

//printf("%d",ndims);
int MPI_Cart_rank(MPI_Comm topocomm, const int coords[], int *myrank);

//MPI_Cart_rank();
MPI_Finalize();
return 0;


}
