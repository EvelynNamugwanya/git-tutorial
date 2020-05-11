   #include <stdio.h>
    #include <stdlib.h>
    #include <mpi.h>
     
    /**
     * MPI_Gather
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
     *                                |   MPI_Gather                   
                                    +-----+-----+-----+--------|
     *                               | process 0(Root)        |       
     *  +-------+-------+-------+ +-------+-------+-------+ +-------+-------+-------+
     * | Value | Value | Value | | Value | Value | Value | | Value | Value | Value |
     * |   0   |  1    |  2  | |  100  |  101    |  102  | |  200  |  201  |  202  |
     * +-------+-------+-------+ +-------+-------+-------+ +-------+-------+-------+   
     **/
    int main(int argc, char* argv[])
    {
        MPI_Init(&argc, &argv);
     
        // Get number of processes and check that 3 processes are used
        int size;
        MPI_Comm_size(MPI_COMM_WORLD, &size);
       
     
        // Get my rank
        int my_rank;
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
       
        // Define my value
        int my_values[size];
        for(int i = 0; i < size; i++)
        {
            my_values[i] = 1*i+  my_rank* 100;
        }
        printf("Process %d, my values = %d, %d, %d.\n", my_rank, my_values[0], my_values[1], my_values[2]);
     
 
  	int buffer_recv[size];


	MPI_Gather(my_values,size,MPI_INT,buffer_recv,size,MPI_INT,0,MPI_COMM_WORLD);
        //MPI_Alltoall(&my_values, 1, MPI_INT, buffer_recv, 1, MPI_INT, MPI_COMM_WORLD);
	if (my_rank==0){
	//printf("The reduced values @ the same index of different processes are %d:\n ", my_rank);
	int i;
	for(i = 0; i < size; i++)
	//buffer_recv[i]=i+1;
	buffer_recv[i];

     	 printf("process 0 has  %d,%d,%d,%d,%d,%d,%d,%d,%d:\n ", 		buffer_recv[0],buffer_recv[1],buffer_recv[2],buffer_recv[3],buffer_recv[4],buffer_recv[5],buffer_recv[6],buffer_recv[7],buffer_recv[8]);
 
    }
        MPI_Finalize();
     
        return EXIT_SUCCESS;
    }
