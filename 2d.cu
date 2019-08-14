#include<cmath>
#include<cstdio>
#define M 2
#define N 2
#define K 2
#define n 4


 
__global__
void multiply(int*A,int*B,int*C)
{
int k,i,j,tmp;
for( i=0;i<M*K;i++)
{    printf("%d\n",A[i]);}

int I=blockIdx.x*blockDim.x+threadIdx.x;

int J=blockIdx.y*blockDim.y+threadIdx.y;
 
if( I < M  || j < N)

{

for( k=0;k<K;k++){
 
C[I*N+J]+= A[I*K+k]*B[k*N+J];

}

}
for (i = 0; i < M*N; i++)
 {   printf("[%d] =%d\n",i, C[i]);
}

}
int main(){
 
int A[M][K]={{1,2},{3,1}};
 int B[K][N]={{2,4},{5,2}};
 int C[M][N]={{0,0},{0,0}};
int* d_A;int* d_B;int* d_C;
 

cudaMalloc(&d_A,n* sizeof(int));//let memory store that m*n space for you of size ints  
cudaMalloc(&d_B,n* sizeof(int));
cudaMalloc(&d_C,n* sizeof(int));

//copy Aand B FROM HOST TO DEVICE  

cudaMemcpy(d_A, &A[0],n* sizeof(int) , cudaMemcpyHostToDevice);
cudaMemcpy(d_B, &B[0],n *sizeof(int) , cudaMemcpyHostToDevice);
cudaMemcpy(d_C, &C[0],n*sizeof(int) , cudaMemcpyHostToDevice);


multiply<<<1,1>>>(d_A,d_B,d_C);
//COPY RESULT BACK TO HOST
cudaMemcpy(&C[0], d_C,n* sizeof(int), cudaMemcpyDeviceToHost);


//printf("%d", C[0]);

cudaFree(A);//TO FREE MEMORY

cudaFree(B);
cudaFree(C);
}
