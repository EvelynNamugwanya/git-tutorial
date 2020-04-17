#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

int *createMatrix (int nrows, int ncols) {
    int *matrix;
    int h, i, j;

    if (( matrix = malloc(nrows*ncols*sizeof(int))) == NULL) {
        printf("Malloc error");
        exit(1);
    }

    for (h=0; h<nrows*ncols; h++) {
        matrix[h] = h+1;//array contents
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

    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Get number of processes
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Get own ID

    int *matrix;

    if (rank == 0) {
        matrix = createMatrix(size, size); // Master process creates matrix
        printf("Initial matrix:\n");
        printArray(matrix, size*size);
    }

    int *procRow = malloc(sizeof(int) *size); // received row will contain size integers
    if (procRow == NULL) {
        perror("Error in malloc 3");
        exit(1);
    }

    if (MPI_Scatter(matrix, size, MPI_INT, /*send one row, which contains number of integers(size) */procRow, size, MPI_INT, 
 	//receive one row, which contains number of integers 
                0, MPI_COMM_WORLD) != MPI_SUCCESS) {

        perror("Scatter error");//	error handlers
        exit(1);
    }

    printf("Process %d received elements: ", rank);
    printArray(procRow, size);

    MPI_Finalize();

    return 0;
}
