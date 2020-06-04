

/* ALLTOALL WITH DYNAMIC MEMORY ALLOCATION */


#include <stdio.h> 
#include <stdlib.h> 
//#include<mpi.h>
#include <string.h>
#include <mpi.h>


  
int main(int argc,char*argv[])
 
{ 
int size,id;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);

   int  i, j, count; /*r=3,c=3; */
  
   int **arr = (int **)malloc(size * sizeof(int *)); //size is the row(r) here i.e(row*sizeof(int *)).however size is everything here
   for (i=0; i<size/*  row */; i++) 
   arr[i] = (int *)malloc(size * sizeof(int)); //size is the column(r) here i.e(colum*sizeof(int *))
  
    
    
printf("Process %d sent elements: ", id);
count = 0; 
    for (i = 0; i <  size; i++) 
      for (j = 0; j < size; j++) 
         arr[i][j] = ++count;  // OR *(*(arr+i)+j) = ++count 
  
    for (i = 0; i <  size; i++) 
      for (j = 0; j < size; j++) 
         printf("%d ", arr[i][j]); 


int *buffer_recv;
    

 	if ((( buffer_recv= malloc(sizeof(int)*size*size))) == NULL) {
        printf("Malloc error");
        exit(1);
        }

    
    


MPI_Alltoall(arr, size, MPI_INT, buffer_recv, size, MPI_INT, MPI_COMM_WORLD);
MPI_Barrier(MPI_COMM_WORLD);
	
printf("Process %d received elements: ", id);
	for (int h=0; h<size*size; h++) {
        buffer_recv[h] = h+1;//array contents
    

        printf("%d ", buffer_recv[h]);
        }
 printf("\n");


 buffer_recv = NULL;
 //delete buffer_recv;

arr = NULL;
//delete arr;

//free(buffer_recv); 

   
MPI_Finalize();

    
   return 0; 
} 


























