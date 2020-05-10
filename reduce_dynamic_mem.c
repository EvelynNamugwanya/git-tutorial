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
       
        int my_rank;
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
        

        //int my_values[size];
	int *my_values = malloc(size * sizeof(int ));
 
        printf("Process %d has the following elements \n", my_rank);
	int z;
	for(int z = 0; z < size; z++)   {
        
            my_values[z] = 1*z+  my_rank* 100;
        
        printf("  %d,",  my_values[z]);
    					 }
 	 printf("  \n");
  	int *buffer_recv;
		if ((( buffer_recv= malloc(size*sizeof(int))) == NULL) ){
        		printf("Malloc error");
        	exit(1);
        							}


	MPI_Reduce(my_values,buffer_recv,size,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
        //MPI_Alltoall(&my_values, 1, MPI_INT, buffer_recv, 1, MPI_INT, MPI_COMM_WORLD);
	if (my_rank==0){
	int h;
	for(h=0;h<size;h++){
		buffer_recv[h];

		printf("The reduced values @  the same index of different processes are %d:\n ", buffer_recv[h]);
			   }
	int sum=0,i;
	for(i = 0; i < size; i++)
	sum+=buffer_recv[i];

     	 	printf("The  sum of the reduced values is %d:\n ", sum);  
 
    			}
        MPI_Finalize();
     
        return EXIT_SUCCESS;
    }
