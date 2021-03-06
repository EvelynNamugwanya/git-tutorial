
// a simple matrix matrix multiplication in CUDA
#include <cstdio>
#include <cmath>

#include "cuda_runtime.h"
#define size 3

#include <cstdio>

//#define BLOCK_SIZE 16
// host code for validating last cuda operation (not kernel launch)
//using namespace std;
#define gpuErrchk(ans) { gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char *file, int line, bool abort=true)
{
   if (code != cudaSuccess)
   {
      fprintf(stderr,"GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
      if (abort) exit(code);
   }
}




//int width= 3;
//int firstCol= 3;
//int secondRo =3;
//int height =3;
// CPU matrix multiplication: code(the normal way to mulitiply matrices)
__global__
void  multiply (int width,int height ,int n ,int* A,int* B,int* C)
{

int x_idx = threadIdx.x + blockIdx.x * blockDim.x;
int y_idx = threadIdx.y + blockIdx.y * blockDim.y;
int d_A[BLOCK_SIZE][BLOCK_SIZE];
    int d_B[BLOCK_SIZE][BLOCK_SIZE];
   int d_C[BLOCK_SIZE][BLOCK_SIZE];


if (x_idx < width && y_idx <height ) {
//int temp = 0;




  for (int i = 0; i <width; i++)
    {
      //printf ("i= %d", i);
      //printf ("\n");
      for (int j = 0; j <height; j++)
{
 //printf ("j= %d", j);
 //printf ("\n");
int temp = 0;
 //printf ("temp= %d", temp);
 //printf ("\n");
 for (int k = 0; k < n; k++)
   {
     //printf ("k= %d", k);
    // printf ("\n");

     temp +=d_A[i][k] *d_B[k][j]; //C is fixed while A is rowWise and B is columnWise
     d_C[i][j] =temp ;
     //printf ("Cij= %d", temp);
    //printf ("\n");
  }
}
    }
}
//************print answer**********
   for (int i = 0; i <width; i++)
    {
      for (int j = 0; j < height; j++)
{
 printf ("%d\n",d_C[i][j]);
}
      printf ("\n");
}


}
//***********close multiply**************
//**************************************************************************************
/* __global__ void display ( int width, int height,int* A,int* B,int* C ){
int d_C[BLOCK_SIZE][BLOCK_SIZE];


     for (int i = 0; i <width; i++)
    {
      for (int j = 0; j < height; j++)
{
 printf ("%d\n",d_C[i][j]);
}
      printf ("\n");
}
} 
*/
//*******************************************************************************************
int
main ()
{
//int* A_O,*B_O,*C_O;
int *d_A, *d_B, *d_C;

//vector<int> A ,B, C;
int A[3][3];
  int B[3][3];
  int C[3][3];
int i,j,n,p;int width= 3;
int height =3;
//int n= 3;

//MATRIX A
printf("Enter number of rows and columns of first matrix\n");
  scanf("%d%d", &width, &n);
//store them
printf("Enter elements of second matrix A\n");
for (i = 0; i < width; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &A[i][j]);
//MATRIX B
printf("Enter number of rows and columns of second matrix\n");
  scanf("%d%d", &p, &height);
//CHEK IF MATRIX ARE VALID
if (n != p)
    printf("The matrices can't be multiplied with each other.\n");
  else
{
    printf("Enter elements of second matrix\n");
 
    for (i = 0; i < p; i++)
      for (j = 0; j < height; j++)
        scanf("%d", &B[i][j]);
}  

//Memory allocaction
//int* A_O,*B_O,*C_O;

//int width= 3;
//int height =3;
//int firstCol= 3;
//int *d_A, *d_B, *d_C; 
//allocate memory on device for  A,B,C

gpuErrchk(cudaMalloc(&d_A, width*height*sizeof(int)));
gpuErrchk(cudaMalloc(&d_B, width*height*sizeof(int)));
gpuErrchk(cudaMalloc(&d_C, width*height*sizeof(int)));

//same
//int *A_O,*B_O,*C_O;
//gpuErrchk(cudaMalloc(&A_O,width *height*sizeof(int)));
//gpuErrchk(cudaMalloc(&B_O,width *height*sizeof(int)));
//gpuErrchk(cudaMalloc(&C_O,width *height*sizeof(int)));

//Copy from device to host
gpuErrchk(cudaMemcpy(d_A, &A[0],width *height*sizeof(int) , cudaMemcpyHostToDevice));
gpuErrchk(cudaMemcpy(d_B, &B[0],width *height*sizeof(int) , cudaMemcpyHostToDevice));
//gpuErrchk(cudaMemcpy(d_C, &C[0],width *height*sizeof(int) , cudaMemcpyHostToDevice));

//call kernel
//dim3 tpb(1);
//dim3 bpg((size+tpb.x-1)/tpb.x, (size+tpb.y-1)/tpb.y);

multiply<<<1,1>>>(width, height , n ,d_A,d_B,d_C);
//display<<<bpg,tpb>>>(width,height,d_A,d_B,d_C);

//copy matrix back to CPU
//gpuErrchk(cudaMemcpy(&A[0], d_A, width *height*sizeof(int), cudaMemcpyDeviceToHost));

//gpuErrchk(cudaMemcpy(&B[0], d_B, width *height*sizeof(int), cudaMemcpyDeviceToHost));

gpuErrchk(cudaMemcpy(&C[0], d_C, width *height*sizeof(int), cudaMemcpyDeviceToHost));

// multiply (A, B, C);//function multiply to multiply AB=C
//  display ( C,width,height);//function diaplay to display matrix ABC
cudaFree(d_A);cudaFree(d_B);cudaFree(d_C);
  return 0;
}

