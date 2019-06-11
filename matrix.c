#include <stdio.h>
#define M 2
#define N 2
#define K 2

  
int main()
{
  
int i,j,k;
  int A[M*K]={1,2,3,1
        
              };
  int B[K*N]={2,4,5,2};
  int C[M*N]={0,0,0,0};
for(int i=0;i<M*K;i++){    printf("%d\n",A[i]);}
//Row Major transversing
for( i=0;i<M;i++){
for( j=0;j<N;j++){
for( k=0;k<K;k++){
    
C[i*N+j]=C[i*N+j]+ A[i*K+k]*B[k*N+j];

   
}
}

}
 for (i = 0; i < M * N; i++){
     printf("[%d] =%d\n",i, C[i]);
 }
  return 0;
}
