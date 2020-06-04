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
        MPI_Init(&argc, &argv);
     
        
        int size;
        MPI_Comm_size(MPI_COMM_WORLD, &size);
       
        int my_rank;
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
        
        // Define my value
	int *my_values;
	my_values=malloc(sizeof(int )*size); //allocating mem to 1D
       
	printf("Process %d, elements include;\n ", my_rank);
	int z;
	for(int z = 0; z < size; z++){
            my_values[z] = z +  my_rank* 100;//elements of array to be stored in memory
        //}
        printf(" %d.\n",  my_values[z]);

                                    }
 		printf("\n");
     
 
  	//Memory allocation for  buffer_recv[size];
	int *buffer_recv;
	if ((( buffer_recv= malloc(sizeof(int)*size*size)) == NULL)) {
        printf("Malloc error");
        exit(1);
                                                                     }

	//printf("Process %d received elements: \n", my_rank); 

	if(MPI_Allgather(my_values,size,MPI_INT,buffer_recv,size,MPI_INT,MPI_COMM_WORLD)!=MPI_SUCCESS)
	{ printf("EROR!!something went wrong!!"); exit(1);}
        
	printf("Process %d received elements: \n", my_rank);
	int h;
	for(h = 0; h < size*size; h++){
	
	buffer_recv[h];

  	printf(" %d ", buffer_recv[h]);
 					}

	printf("\n");
  
        MPI_Finalize();
     
        return EXIT_SUCCESS;
    }
