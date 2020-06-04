#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
//int *array;
int rank,size,i,j;
int array[size][size];
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
MPI_Datatype data_type;
size= 3;
//array = (int *)malloc(size*size*sizeof(int));
if(rank==0)
{
//int t= 0;
for(i=0;i<size;i++) 	{
 for(j=0;j<size;j++){ 
	array[i][j]=i*size+j;
           //t++; 
		    }
			
 }
printf("process 0z matrix b4 broadcasting");

for (i= 0; i <size;i++)
{
for(j= 0; j < size; j++)
printf("%d [%d]\t",array[i][j],rank);
printf("\n");
}

}
MPI_Bcast(array,size,MPI_INT,0,MPI_COMM_WORLD);
MPI_Barrier(MPI_COMM_WORLD);
printf("process %d printing matrix:\n",rank);
for (i= 0; i <size;i++)
{
for(j= 0; j < size; j++)
printf("%d [%d]\t",array[i][j],rank);
printf("\n");
}
MPI_Finalize();
}
