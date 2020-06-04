#include <stdio.h>

int DRI_Globaldata_create(int dimsi[],int nd,int global) {
global=0;
  for (int i = 0; i < nd; i++) {
		global += dimsi[i]*dimsi[i+1];
  
 //store=globaldata;
  }
  return global;
}


int main (int argc,char**argv){

int result=0, dim[] = {1,16};int n=2;int g =0;
DRI_Globaldata_create(dim,n, g); 
result = DRI_Globaldata_create(dim,n, g);
    printf("Result = %d", result );





return 0;


}

