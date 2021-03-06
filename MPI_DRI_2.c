/*


write anormal MPI program with;
	-MPI_Init
	-MPI_Finalize
	-MPI_Comm_Size
	-MPI_Comm_Rank
	-MPI-Send/Bcast/all to all
	-MPI_Recev
-make it broadcast.
-add dri 0perations 	
 int DRI_Init,DRI_Finalize DRI_Globaldata_create -->create datatype DRI_Globaldata & return object gdo.BROADCAST gdo to given processes

*/
#include <mpi.h>
#include <stdio.h>
#include<stdlib.h>
#include "dri.h"

#define NDIMS 2
 //int dimsizes[NDIMS] = {1, 16};
/*
typedef struct DRI_Globaldata{
	int ndims;
	int *a;
	int dimsizes[];

	}DRI_Globaldata;//created datatype DRI_Globaldata  


*/


int DRI_Globaldata_create(int dimsizes[],int ndims,int globaldata) {

  for (int i = 0; i < ndims; ++i) {
		globaldata += dimsizes[i]*dimsizes[i+1];
  }

  return globaldata;
}



int main (int argc,char**argv){

	MPI_Init(&argc,&argv);
	int DRI_Init (int *nargs, char ***args);
 	
	int result, dimsizes[] = {1,16};int ndims=2;int globaldata =0;

    
    result = DRI_Globaldata_create(dimsizes,ndims, globaldata); 
    printf("Result = %d", result);

	
/*
int DRI_Globaldata_create ( DRI_Globaldata *gdo){//DRI_Globaldata_create(NDIMS, global_dims, &gdo);


	int dimsizes[NDIMS] = {1, 16};
	gdo->dimsizes;
	gdo->ndims=NDIMS;
for(int i=0;i<gdo->ndims;i++) {
   
	DRI_Globaldata *gdo=malloc(sizeof(DRI_Globaldata));
	gdo->dimsizes[i];
	gdo->dimsizes[i+1];


int store;


store=gdo->dimsizes[i]*gdo->dimsizes[i+1];

	return store;

				}
						} 

*/





 
int size,rank,i,*sendbuf,root=0,datasize=16;/* gdo object should replace datasize to be broadcasted to all processes  */
MPI_Comm_size(MPI_COMM_WORLD,&size);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
sendbuf=(int *)malloc(datasize*size*sizeof(int));
printf("values @ senderbuf are-:)");
if(rank == root)  
   {
     
		
	for (i=0;i<datasize;i++){
	 sendbuf[i]=i+2;
    
	printf("%d,""",sendbuf[i]);
				 }	                          
    }
			
/* every process calls mpi_bcast so the contents of root are given to every process*/
MPI_Bcast(sendbuf,datasize,MPI_INT,root,MPI_COMM_WORLD);    
	for (i=0;i<datasize;i++){

	printf("[%d]  %d \t",rank,sendbuf[i]);
	

				}
int DRI_Finalize();
MPI_Finalize();
return 0;


}

