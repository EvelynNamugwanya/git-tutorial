#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char**argv)
{
   int *sendbuf = 0, *recvbuf = 0;
   int *displs = 0, *sendcnts = 0,*recvcnts = 0;
                    
   int rank, size;
   int root = 0;

   int datasize = 64;

   MPI_Init(&argc,&argv);
   MPI_Comm_size(MPI_COMM_WORLD,&size); 
   MPI_Comm_rank(MPI_COMM_WORLD,&rank);

   recvbuf=(int *)malloc(datasize*1*sizeof(int)); /* all processes have the receive buf, including the root */
   
int i ;
   if(rank == root)  /* I'll be the root! */
   {
      sendbuf=(int *)malloc(datasize*size*sizeof(int)); /* only root has this data */
      displs=(int *)malloc(size*sizeof(int)); /* 1 displacement per destination rank */
      sendcnts=(int *)malloc(size*sizeof(int)); /* 1 send count per destination rank */

      /* data choices so you can identify what was received */

        for(i = 0; i < size*datasize; ++i){
        sendbuf[i] = i;


         				  }
	for (i=0; i<size; ++i) { 
        displs[i] = i*datasize*1; /*offset,and  1 is for stride*/
        sendcnts[i] = 64-i; /*process0=64,process1=63,process2=62,process3=61;*/
   			       } 
	
			//}
      //set displacements: 
 	/* 
	for(int i = 0; i < size; ++i)
        {
 		displs[i] = i*datasize; //0, datasize, 2*datasize, ..., (size-1)*datasize 
      	}

      //set sendcounts: 
     for(int i = 0; i < size; ++i)
        {
 	 sendcnts[i] = datasize;   
        }
                                      
	*/
	
   
  }  
   else
   {
      
	for(int i = 0; i < datasize; ++i)
        recvbuf[i] = -1;/*can also be 0 */

     }

 //printf("5%d\n",sendbuf[i]);

   /*
int MPI_Scatterv(
  void *sendbuf,
  int *sendcnts,
  int *displs,
  MPI_Datatype sendtype,
  void *recvbuf,
  int recvcnt,
  MPI_Datatype recvtype,
  int root,
  MPI_Comm comm
);

    */recvcnts=(int *)malloc(size*size*sizeof(int));

   MPI_Scatterv(sendbuf, sendcnts, displs, MPI_INT, recvbuf, datasize, MPI_INT , root, MPI_COMM_WORLD);

   /* print out what we got: */

   for(int i = 0; i < datasize; ++i)
   {
      printf("%5d: recvbuf[%5d]=%5d\n", rank, i, recvbuf[i]);
   }
  
   if(rank == root)  /* I'll be the root! */
   {
     free(sendbuf); sendbuf = 0;
     free(sendcnts); sendcnts = 0;
     free(displs); displs = 0;
   }

   free(recvbuf); recvbuf = 0;

   MPI_Finalize();

   return 0;
}
