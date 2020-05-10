#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

int *createMatrix (int nrows, int ncols) {
    int *matrix;
    int h, i, j;

    if (( matrix = malloc(nrows*ncols*sizeof(int))) == NULL) {//int *matrix = (int*) malloc(nrows*ncols*sizeo(int));
        printf("Malloc error");
        exit(1);
    }

    for (h=0; h<nrows*ncols; h++) {
        matrix[h] = h+1;
    }

    return matrix;
}

void printArray (int *row, int nElements) {
    int i;
    for (i=0; i<nElements; i++) {
        printf("%d ", row[i]);
    }
    printf("\n");
}

int main (int argc, char **argv) {

    if (MPI_Init(&argc, &argv) != MPI_SUCCESS) {
        perror("Error initializing MPI");
        exit(1);
    }

    int p, id;
    MPI_Comm_size(MPI_COMM_WORLD, &p); // Get number of processes
    MPI_Comm_rank(MPI_COMM_WORLD, &id); // Get own ID or rank

    int *matrix;

   // if (id == 0) {
printf("Process %d had elements: ", id);  
        matrix = createMatrix(p, p); // Master process creates matrix
      //printf("Process %d had elements: ", id);   
        //printf("Initial matrix:\n");
           
        printArray(matrix, p*p);
   // }
//arr[row] = (int*)(malloc(columns*sizeof(int)))

   // int *procRow = malloc(sizeof(int*)*p);
int *procRow /* an integer  pointer to the address of the first element.*/= (int*/* Type casting the return of malloc to an integer pointer*/)(malloc(p*sizeof(int)));/* number of elements(bytes)*size of one unit   */
 // received row will contain p integers        

           
   if (procRow == NULL) {
       perror("Error in malloc 3");
       exit(1);
  }

/*
arr  = malloc(sizeof(int *) * rows);
arrayData = malloc(sizeof(int) * columns * rows);

for(i = 0; i < rows; i++)
     arr[i]  = arrayData + i * columns ;

*/
//calloc has two parameters
//int *p =(int*)calloc(3//number of elements,sizeof(int)//size of datatype in bytes)
 
//it also initialises memory to zero unlike malloc which initializes memory to gabage values incase you dont initialise memory
//free(A)  is to deallocate memory.and then you can use As space again







MPI_Alltoall(matrix, p*p, MPI_INT, procRow,p*p, MPI_INT, MPI_COMM_WORLD);
 
    

    printf("Process %d received elements: ", id);
    printArray(procRow, p*p);
//printArray(procRow, p);
//printf("The ALLtoall Values   processes are %d,%d,%d:\n ", procRow[0],procRow[1],procRow[2]);
//printf("Process %d, procRow = %d, %d, %d,%d, %d, %d,%d, %d, %d.\n", id, procRow[0], procRow[1], procRow[2],procRow[3], procRow[4], procRow[5],procRow[6], procRow[7], procRow[8]);
	//int sum=0,i;
free(procRow);
    MPI_Finalize();

    return 0;
}
