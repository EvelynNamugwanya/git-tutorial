   #include <stdio.h>
    #include <stdlib.h>
    #include <mpi.h>
     
    
    int main(int argc, char* argv[])
    {
        
        int *displs,i,*rcounts, *my_values;
	MPI_Init(&argc, &argv);
     
        int size;int datasize = 64;
        MPI_Comm_size(MPI_COMM_WORLD, &size);
       
     
        // Get my rank
        int my_rank;
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
       
        
	my_values=(int *)malloc(datasize*size*sizeof(int));
	
        for(int i = 0; i < datasize*size; i++)
        			{
            my_values[i] = i;
        
     
     
 				}
	int *buffer_recv;
	

  	buffer_recv=(int *)malloc(datasize*size*sizeof(int));
	displs=(int *)malloc(size*size*sizeof(int));
	rcounts=(int *)malloc(size*size*sizeof(int));

        

         				  
		for (i=0; i<size; ++i) { 
        	displs[i] = i*datasize*1; /*offset,and  is for stride*/
        	rcounts[i] = 64-i; /*process0=64,process1=63,process2=62,process3=61;*/
   			
	                        }


        MPI_Gatherv(my_values,64-my_rank,MPI_INT,buffer_recv,rcounts,displs,MPI_INT,0,MPI_COMM_WORLD);/*MPI_Gatherv( sptr, 1, stype, rbuf, rcounts, displs, MPI_INT, root, comm); */
        	if (my_rank==0){
        
	
       
			for(int i = 0; i < datasize*size; i++){
        			printf("%5d: recvbuf[%5d]=%5d\n", my_rank, i, buffer_recv[i]);
	
								}

    				}
 
     free(rcounts); rcounts = 0;
     free(displs); displs = 0;
     free(buffer_recv); buffer_recv = 0;
      
 MPI_Finalize();
     
        
return EXIT_SUCCESS;
    }
