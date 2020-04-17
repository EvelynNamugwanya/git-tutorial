#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
      

int main(int argc, char* argv[])
    {
        MPI_Init(&argc, &argv);
     int i,j;
        // Get number of processes and check that 3 processes are used
        int size;
        MPI_Comm_size(MPI_COMM_WORLD, &size);//number of processes
        if(size != 3)//tried 16,32 64
        {
            printf("program can run on 10 MPI processes.\n");
            MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
        }
     
        // Get my rank
        int my_rank;
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
     
        // Define my value
        int my_values[size][size];//increased the dimensions of the matrix with the number pf processes
for( i = 0; i < size; i++){
	for( j = 0; j < size; j++){

my_values[i][j] =  i*3+size* j;//each process sends 3 digits in araw.e.g 300,400,500 which transposed as its received	
	
    			 }
				}
printf("process %d printing matrix:\n",my_rank);
for (i= 0; i <size;i++)
	{
	for(j= 0; j < size; j++)
printf("%d \t",my_values[i][j]);

printf("\n");
	}
        
printf("\n");


		


int buffer_recv[size][size];
        MPI_Alltoall(my_values, size*size, MPI_INT, buffer_recv, size*size, MPI_INT, MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);
       
for (i= 0; i <size;i++)
	{
	for(j= 0; j < size; j++)
//printf("%d,[%d]\t",buffer_recv[i][j],my_rank);
printf("%d: (%d,%d)=[%d]\t",my_rank,i,j,buffer_recv[i][j]);
		//printf("at process [%d],values collected %d \t",my_rank,buffer_recv[i][j]);printf("%d [%d]\t",my_values[i][j],my_rank);
printf("\n");
	}


		//does each digit have a buffer---->no its the same buffer but @ different indices                                      
        MPI_Finalize();
     
        return EXIT_SUCCESS;
    }

		
