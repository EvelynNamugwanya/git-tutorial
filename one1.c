//6/01/2020.Evelyn Namugwanya
#include "mpi.h"
#include<stdio.h>
#define BUFSIZE 100

int main(int argc ,char *argv[])
{
int i,myrank ,numprocs,buf[BUFSIZE];
MPI_Status status;
FILE *myfile;


MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
for(i =0;i<BUFSIZE;i++)
buf[i]=myrank *BUFSIZE+i;
if(myrank !=0)
MPI_Send(buf,BUFSIZE,MPI_INT,0,99,MPI_COMM_WORLD);

else{
myfile = fopen("testfile","W");

fwrite(buf,sizeof(int),BUFSIZE,myfile);//process 0 writting to its self

for(i =1;i<numprocs;i++){

MPI_Recv(buf,BUFSIZE,MPI_INT,i,99,MPI_COMM_WORLD,&status);//process 0 is receiving msg /sent buf from all the process

fwrite(buf,sizeof(int),BUFSIZE,myfile);//from process 0 we come up with one big array i.e we write to myfile we form one big file

}
fclose(myfile);
}
MPI_Finalize();
return 0;
}
