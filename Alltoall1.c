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
        if(size != 64)//tried 16,32 64
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

my_values[i][j] =  i*3+my_rank* j;//each process sends 3 digits in araw.e.g 300,400,500 which transposed as its received	
	
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


//the receiver buffer
   
    /* int buffer_recv[1][3];--->i also made it that dimension for easy analisation-->if it was correctly for that then its good for any data(matrix)tho i guess at some point i may need to allocate memory-->that means that if there are 3 processors each processor has process has 1 row and 3 columns output will be something like this
0 [1]	1 [1]	2 [1]	
0 [2]	2 [2]	4 [2]	
0 [0]	0 [0]	0 [0]	
0,by [0]	0,by [0]	0,by [0]	
0,by [1]	1,by [1]	2,by [1]	
0,by [2]	2,by [2]	4,by [2]   if you follow those indexes closely you release they have been reshuffled and thats the work of mpi all to all

*/

//printf("***after MPI Alltoall****");


int buffer_recv[size][size];
        MPI_Alltoall(&my_values, size, MPI_INT, buffer_recv, size, MPI_INT, MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);
       
for (i= 0; i <size;i++)
	{
	for(j= 0; j < size; j++)
printf("%d,-[%d]\t",buffer_recv[i][j],my_rank);
	//printf("at process [%d],values collected %d \t",my_rank,buffer_recv[i][j]);printf("%d [%d]\t",my_values[i][j],my_rank);
printf("\n");
	}


//does each digit have a buffer---->no its the same buffer but @ different indices                                      
        MPI_Finalize();
     
        return EXIT_SUCCESS;
    }

