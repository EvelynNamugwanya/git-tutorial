#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>


int main(int argc, char* argv[])
      {
    MPI_Init(&argc, &argv);
       	int i,j;
        // Get number of processes and check that 3 processes are used
        int size;
        int *my_values;

     MPI_Comm_size(MPI_COMM_WORLD, &size);//number of processes
       if(size != 3){//tried 16,32 64
          
            printf("program can run on 10 MPI processes.\n");
            MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
                  }
     
int my_rank;
       MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
     
  my_values = (int*)malloc(size*size*sizeof(int));
        // Get my rank
       
        // Define my value
        //int my_values[size][size];//increased the dimensions of the matrix with the number pf processes
int t;
        for( t = 0; t< size*size; i++)    {
	  

             my_values[t] = t+1;//each process sends 3 digits in araw.e.g 300,400,500 if size is 3 which transposed as its received thats what i think	
	
    			           }
				     
     printf("process [%d] printing matrix:\n",my_rank);
	for (t= 0; t <size*size;t++)
	{
	
          printf("%d \t",my_values[t]);

           printf("\n");
	}
        
    


 int *buffer_recv = malloc(sizeof(int) * size); // received row will contain p integers
    if (buffer_recv == NULL) {
        perror("Error in malloc 3");
        exit(1); }

      //int buffer_recv;
     MPI_Alltoall(&my_values,size, MPI_INT, buffer_recv,size, MPI_INT, MPI_COMM_WORLD);
 
    //MPI_Barrier(MPI_COMM_WORLD);


 printf("Process [%d] received elements: ",my_rank);
   // printArray(buffer_recv, t);
for (int i= 0; i <size*size;i++)
	{
	
          printf("%d \t",buffer_recv[i]);}

           printf("\n");
	//}





//does each digit have a buffer---->no its the same buffer but @ different indices       


                              
        MPI_Finalize();
     
        return EXIT_SUCCESS;
    }

