 #include <stdio.h>
    #include <stdlib.h>
    #include <mpi.h>
     
    /**
     * MPI_Allgather
       All Elements of different processes are gathered at all different processes
     *
     * +-----------------------+ +-----------------------+ +-----------------------+
     * |       Process 0       | |       Process 1       | |       Process 2       |
     * +-------+-------+-------+ +-------+-------+-------+ +-------+-------+-------+
     * | Value | Value | Value | | Value | Value | Value | | Value | Value | Value |
     * |   0   |  1    |  2  | |  100  |  101    |  102  | |  200  |  201  |  202  |
     * +-------+-------+-------+ +-------+-------+-------+ +-------+-------+-------+
     *            |                                   |                        |       
     *       | process 0      
     *  +-------+-------+-------+ +-------+-------+-------+ +-------+-------+-------+
     * | Value | Value | Value | | Value | Value | Value | | Value | Value | Value |
     * |   0   |  1    |  2  | |  100  |  101    |  102  | |  200  |  201  |  202  |
     * +-------+-------+-------+ +-------+-------+-------+ +-------+-------+-------+ 
             | process 1          
     *  +-------+-------+-------+ +-------+-------+-------+ +-------+-------+-------+
     * | Value | Value | Value | | Value | Value | Value | | Value | Value | Value |
     * |   0   |  1    |  2  | |  100  |  101    |  102  | |  200  |  201  |  202  |
     * +-------+-------+-------+ +-------+-------+-------+ +-------+-------+-------+ 
              | process 2         
     *  +-------+-------+-------+ +-------+-------+-------+ +-------+-------+-------+
     * | Value | Value | Value | | Value | Value | Value | | Value | Value | Value |
     * |   0   |  1    |  2  | |  100  |  101    |  102  | |  200  |  201  |  202  |
     * +-------+-------+-------+ +-------+-------+-------+ +-------+-------+-------+   
     **/
    int main(int argc, char* argv[])
    {
        MPI_Init(&argc, &argv);//initi
     
        
        int size;
        MPI_Comm_size(MPI_COMM_WORLD, &size);
       
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

//int six=6;
	int MPI_Neighbor_allgatherv(my_values,size,MPI_INT,buffer_recv,size,MPI_INT,MPI_COMM_WORLD);
        
	printf("Process %d received elements: ", my_rank); 
	int i;
	for(i = 0; i < size; i++)
	
	buffer_recv[i];

  printf(" %d,%d,%d,%d,%d,%d,%d,%d,%d:\n ", buffer_recv[0],buffer_recv[1],buffer_recv[2],buffer_recv[3],buffer_recv[4],buffer_recv[5],buffer_recv[6],buffer_recv[7],buffer_recv[8]);
 
  
        MPI_Finalize();
     
        return EXIT_SUCCESS;
    }
