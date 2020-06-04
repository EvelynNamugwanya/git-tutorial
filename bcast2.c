#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
//Broadcasting 3*3 matrix
int *array;
int rank,size,i,j;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
MPI_Datatype data_type;
size= 3;
array = (int *)malloc(size*size*sizeof(int));
if(rank==0)
{
int t= 0;
for(i=0;i<size;i++) 	{
 for(j=0;j<size;j++){ 
	array[i*size+j]=t++; 
		    }
			 }
}

printf("%d [%d]\t",array[i*size+j],rank);
printf("\n");
MPI_Bcast(array,size*size,MPI_INT,0,MPI_COMM_WORLD);
MPI_Barrier(MPI_COMM_WORLD);
printf("process %d printing matrix:\n",rank);
for (i= 0; i <size;i++)
{
for(j= 0; j < size; j++)
printf("%d [%d]\t",array[i*size+j],rank);
printf("\n");
}
MPI_Finalize();
}
