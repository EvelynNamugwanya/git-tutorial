
int DRI_Init(int *nargs, char ***args);

int DRI_Finalize();

typedef struct DRI_Globaldata{
	int ndims;
	int *a;
	int dimsizes[];

	}DRI_Globaldata;/*created datatype DRI_Globaldata  */


/*  int DRI is initialized ();checks whether DRI has been initialized. If (it has been initialized ){return 1}else return 0;*/
			//MPI uses int MPI_Initialized(int *flag)


//int DRI_Overlap_create ( DRI_Overlaptype_ovrtype, unsigned int num_pos,DRI_Overlap *overlap);
