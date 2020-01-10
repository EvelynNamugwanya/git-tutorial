#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>



#define NUM_SPAWNS 2//can also just define it as np
int main (int argc,char*argv[]){

int np= NUM_SPAWNS;
int errcodes[NUM_SPAWNS];
MPI_Comm parentcomm;
MPI_Comm intercomm;


MPI_Init(&argc,&argv);//starr mpi

MPI_Comm_get_parent(&parentcomm);//remote access memory
if(parentcomm==MPI_COMM_NULL)//WHAT DOES MPI_COMM_NULL MEAN?

{ 
//Create 2 more processess 
MPI_Comm_spawn("spawn_example",MPI_ARGV_NULL/*like length*/,np,MPI_INFO_NULL,0,MPI_COMM_WORLD,&intercomm,errcodes);//MPI_ARGV_NULL- like length of the argument- Passing an argv of MPI_ARGV_NULL to MPI_COMM_SPAWN results in main receiving argc of 1 and an argv whose element 0 is (conventionally) the name of the program.


printf("I'm the parent.\n");
}else
{
printf("iam a parent.\n");
}

fflush(stdout);//to make the operating system fush any buffers of the underlieing files.//used to clear the buffer 
MPI_Finalize();
return 0;

}
