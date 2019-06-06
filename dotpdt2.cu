#include<cmath> 
#include<cstdio>
//#define BLOCKSIZE 1 

__global__
void dotproduct(int* A,int*B,int*C,int M,int N,int K)
{
printf("%d %d\n", A[0],A[1]);

printf("%d %d\n", B[0],B[1]);

printf("%d %d\n", C[0],C[1]);


int I=blockIdx.x*blockDim.x+threadIdx.x;

int J=blockIdx.y*blockDim.y+threadIdx.y;
int temp =0;

if( I < M  || J < N){




//what is Bkj=B[k*N+J]; 
//int temp =0; 
for(int k=0;k<K;k++){
temp +=A[I*K+k]*B[k*N+J];
}
}
C[I*N+J]=temp;
//} 
printf("%d\n", C[I*N+J]);


//} 
}
int main(){

//int *A=(iny ) 
int A[2]={1,2};
int B[2]={1,1};
int C[2]={0,0};
int* d_A;int* d_B;int* d_C;
//int* A;int* B;int* C; 

int M=2;
int N=2;
int K=2;
//allocating space for variables on device 

cudaMalloc(&d_A, M *sizeof(int));//let memory store that m*n space for you of size ints 
cudaMalloc(&d_B, M *sizeof(int));
cudaMalloc(&d_C, sizeof(int));
/*        //alocate space for variables on the host 
cudaMalloc(&A, M *N*sizeof(int));//let memory store that m*n space for you of size ints 
cudaMalloc(&B, M *N*sizeof(int)); 
cudaMalloc(&C, M *N*sizeof(int)); 
*/


//copy Aand B FROM HOST TO DEVICE 

cudaMemcpy(d_A, &A[0],M *sizeof(int) , cudaMemcpyHostToDevice);
cudaMemcpy(d_B, &B[0],M *sizeof(int) , cudaMemcpyHostToDevice);
cudaMemcpy(d_C, &C[0],sizeof(int) , cudaMemcpyHostToDevice);
dotproduct<<<1,1>>>(d_A,d_B,d_C,M,N,K );

//COPY RESULT BACK TO HOST
cudaMemcpy(&C[0], d_C, sizeof(int), cudaMemcpyDeviceToHost);
//printf("%d", C[0]);

cudaFree(A);//TO FREE MEMORY

cudaFree(B);
cudaFree(C);
}



















