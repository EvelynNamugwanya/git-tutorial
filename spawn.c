#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>



#define NUM_SPAWNS 2//can also just define it as np
int main (int argc,char*argv[]){

int np= NUM_SPAWNS;
int errcodes[NUM_SPAWNS];
MPI_comm parentcomm,intercomm;


MPI_int(&argc,&argv);//starr mpi

MPI_comm get parent(&parentcomm);
if(parentcomm==MPI_COMM_NULL)//WHAT DOES MPI_COMM_NULL MEAN?

{ 
//Create 2 more processess 
MPI_comm_spawn("spawn_example",MPI_ARGV_NULL/*like length*/,np,MPI_INFO_NULL,0,MPI_COMM_WORLD,&intercomm,errcodes);//MPI_ARGV_NULL- like length of the argument- Passing an argv of MPI_ARGV_NULL to MPI_COMM_SPAWN results in main receiving argc of 1 and an argv whose element 0 is (conventionally) the name of the program.

       
printf("I'm the parent.\n");
}else
{
printf("iam a parent.\n");
}

fflush(stdout);//to make the operating system fush any buffers of the underlieing files.//used to clear the buffer 
MPI_Finalize();
return 0;

}


/*
 MPI_INIT in the children may not return until all parents have called MPI_COMM_SPAWN. In this sense, MPI_COMM_SPAWN in the parents and MPI_INIT in the children form a collective operation over the union of parent and child processes. The intercommunicator returned by MPI_COMM_SPAWN contains the parent processes in the local group and the child processes in the remote group. The ordering of processes in the local and remote groups is the same as the as the ordering of the group of the comm in the parents and of MPI_COMM_WORLD of the children, respectively. This intercommunicator can be obtained in the children through the function MPI_COMM_GET_PARENT.

*/

/*

An implementation may automatically establish communication before MPI_INIT is called by the children. Thus, completion of MPI_COMM_SPAWN in the parent does not necessarily mean that MPI_INIT has been called in the children (although the returned intercommunicator can be used immediately). ( End of advice to users.) 

*/
