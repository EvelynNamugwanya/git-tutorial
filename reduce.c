   #include <stdio.h>
    #include <stdlib.h>
    #include <mpi.h>
     
    /**
     * 
     *
     * +-----------------------+ +-----------------------+ +-----------------------+
     * |       Process 0       | |       Process 1       | |       Process 2       |
     * +-------+-------+-------+ +-------+-------+-------+ +-------+-------+-------+
     * | Value | Value | Value | | Value | Value | Value | | Value | Value | Value |
     * |   0   |  1    |  2  | |  100  |  101    |  102  | |  200  |  201  |  202  |
     * +-------+-------+-------+ +-------+-------+-------+ +-------+-------+-------+
     *            |                         |                        |       
     *            |                         |                       |       
     *            |___|_____________|_      |      ________________|       
     *                                |     |     |      
     *                                |   Reduction                    
                                    +-----+-----+-----+--------|
     *                               | proc0| proc1| proc2|  |       
     *                               +-----+-----+-----+ -----|   
     *                              |    Process 0            |  
     *                              +-----------------+ ------       
     **/
    int main(int argc, char* argv[])
    {
        MPI_Init(&argc, &argv);
     
        // Get number of processes and check that 3 processes are used
        int size;
        MPI_Comm_size(MPI_COMM_WORLD, &size);
       /* if(size != 3)
        {
            printf("This application is meant to be run with 3 MPI processes.\n");
            MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
        } */
     
        // Get my rank
        int my_rank;
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
        //int i;
        // Define my value
        int my_values[size];
        for(int i = 0; i < size; i++)
        {
            my_values[i] = 1*i+  my_rank* 100;
        }
        printf("Process %d, my values = %d, %d, %d.\n", my_rank, my_values[0], my_values[1], my_values[2]);
     
 
  	int buffer_recv[size];


	MPI_Reduce(&my_values,&buffer_recv,size,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
        //MPI_Alltoall(&my_values, 1, MPI_INT, buffer_recv, 1, MPI_INT, MPI_COMM_WORLD);
	if (my_rank==0){
	printf("The reduced values @ the same index of different processes are %d,%d,%d:\n ", buffer_recv[0],buffer_recv[1],buffer_recv[2]);
	int sum=0,i;
	for(i = 0; i < size; i++)
	sum+=buffer_recv[i];

     	 printf("The reduced values is %d:\n ", sum);  
 //printf("The reduced values is %d,%d: ", buffer_recv[0],buffer_recv[1],buffer_recv[2]);
    }
        MPI_Finalize();
     
        return EXIT_SUCCESS;
    }
