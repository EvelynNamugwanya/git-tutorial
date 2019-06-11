
#include<cmath>
#include<cstdio>
#define M 2
#define N 2
#define K 2
__global__
void matrix_multiply(int* A,int*B,int*C)
{

//printf("%d %d\n", A[0],A[1]);

//printf("%d %d\n", C[0],C[1]);
for(int i=0;i<M*K;i++){    printf("%d\n",A[i]);}
for(int i=0;i<K*N;i++){    printf("%d\n",B[i]);}

int I=blockIdx.x*blockDim.x+threadIdx.x;

int J=blockIdx.y*blockDim.y+threadIdx.y;

if( I < M  || J < N)
{

for( i=0;i<M;i++){
for( j=0;j<N;j++){
for( k=0;k<K;k++){
C[I*N+J]=C[I*N+J]+ A[I*K+k]*B[k*N+J];

}
}

}

}
/********************************************************
row major 

 

what is Cij =C[I*n+J]; 


What is Aik=A[i*K+k]; 


what is Bkj=B[k*N+J]; 
*/**************************************************************************

}
for (i = 0; i < M * N; i++){
     printf("[%d] =%d\n",i, C[i]);

}
 
}
int main(){

int A[M*K]={1,2,3,1};
  int B[K*N]={2,4,5,2};
  int C[M*N]={0,0,0,0};
int* d_A;int* d_B;int* d_C;

//allocating space for variables on device 

cudaMalloc(&d_A,M * sizeof(int));//let memory store that m*n space for you of size ints 
cudaMalloc(&d_B, K * sizeof(int));
cudaMalloc(&d_C, sizeof(int));


//copy A and B FROM HOST TO DEVICE 

cudaMemcpy(d_A, &A[0],M* sizeof(int) , cudaMemcpyHostToDevice);
cudaMemcpy(d_B, &B[0],K *sizeof(int) , cudaMemcpyHostToDevice);
cudaMemcpy(d_C, &C[0],sizeof(int) , cudaMemcpyHostToDevice);

matrix_multiply<<<1,1>>>(d_A,d_B,d_C);

//COPY RESULT BACK TO HOST
cudaMemcpy(&C[0], d_C, sizeof(int), cudaMemcpyDeviceToHost);
cudaMemcpy(&C[1], d_C, sizeof(int), cudaMemcpyDeviceToHost);
//printf("%d", C[0]);

cudaFree(A);//TO FREE MEMORY

cudaFree(B);
cudaFree(C);
}

