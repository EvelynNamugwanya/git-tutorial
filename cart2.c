#include <stdio.h> 
#include <stdlib.h> 
//#include<mpi.h>
#include <string.h>
#include <mpi.h>

 /* A two-dimensional torus of 12 processes in a 4x3 grid */
int main(int argc, char *argv[])
{
    int rank, size;
    MPI_Comm comm;
    int dim[2], period[2], reorder;
    int coord[2], id;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    dim[0]=3; dim[1]=3;
    period[0]=1; period[1]=0;
    reorder=1;
    MPI_Cart_create(MPI_COMM_WORLD, 2, dim, period, reorder, &comm);
/*  
  if (rank == 5)
    {
        MPI_Cart_coords(comm, rank, 2, coord);//coordinates
        printf("Rank %d coordinates are %d %d\n", rank, coord[0], coord[1]);fflush(stdout);
    }
    if(rank==0)//so how many process have rank 0
    {
        coord[0]=3; coord[1]=1;
        MPI_Cart_rank(comm, coord, &id);//to get the rank/id-**however i thought 0 is the rank
        printf("The processor at position (%d, %d) has rank %d\n", coord[0], coord[1], id);fflush(stdout);
    }
*/
int *my_values;
	my_values=malloc(sizeof(int )*size); //allocating mem to 1D
       
	printf("Process %d, elements include;\n ", rank);
	int z;
	for(int z = 0; z < size; z++){
            my_values[z] = z +  rank* 100;//elements of array to be stored in memory
        //}
        printf(" %d,",  my_values[z]);

                                    }
 		printf("\n");

int *buffer_recv;
	if ((( buffer_recv= malloc(sizeof(int)*size*size)) == NULL)) {
        printf("Malloc error");
        exit(1);
}

int MPI_Neighbor_allgatherv(my_values,size,MPI_INT,buffer_recv,size,MPI_INT,MPI_COMM);//remove this error and find out the correct way it shoud be written

printf("Process %d received elements: \n", rank);
	int h;
	for(h = 0; h < size*size; h++){
	
	buffer_recv[h];

  	printf(" %d ", buffer_recv[h]);
 					}

	printf("\n");

                   


    MPI_Finalize();
    return 0;
}
