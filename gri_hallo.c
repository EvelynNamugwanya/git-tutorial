//
// OpenDRI project
//
// Author: Evelyn Namugwanya
//
// University of Tennessee at Chattanooga
// See LICENSE file for details on open-source license
//
// This follows the DRI 1.0 specification from September, 2002
//
// This is a test-suite program---exercises very basic DRI.
//

#include <mpi.h>
#include <stdio.h>
#include<stdlib.h>
#include "dri.h"

#define NDIMS 2

int main (int argc, char**argv)
{
        int error;
	int dimsizes[NDIMS] = {1, 16};

        DRI_Globaldata gdo;
        printf("Hello world");

	MPI_Init(&argc,&argv);

	// add error tests later!
	error = DRI_Init(&argc,&argv);
        error = DRI_Globaldata_create(&gdo);
	error = DRI_Globaldata_create(NDIMS, dimsizes, &gdo);
	error = DRI_Globaldata_destroy(&gdo);
	error = DRI_Finalize();

	
	MPI_Finalize();

        return 0;
}
