// pcp from the Scalable Unix Tools,in MPI-2
#include "mpi.h"
#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#define BUFSIZE 256*1024
#define CMDSIZE 80
//#ifndef MAXPATHLEN
#define MAXPATHLEN 1024
#include <string.h>


int main(int argc,char*argv[]){

int  num_hosts,mystatus,allstatus,done,numread,infd,outfd;
char outfilename[MAXPATHLEN],controlmsg[CMDSIZE];
char soft_limmit[20];
MPI_Info hostinfo;
MPI_Comm pcpslaves,all_processes;

MPI_Init(&argc,&argv);
//begining the master of the copy program
 makehostlist(argv[1],"targets",&num_hosts);//makes the list of hosts -PASSES OUT THE FIRST ARGUMENT & WRITES OUT AHOSTFILE(w/c is understood by MPI_Comm_Spawn via MPI_Info_set------->hostinfo ) CALLED "targets"(2nd argument),and number of hosts
MPI_Info_create(&hostinfo);//address to host info
MPI_Info_set(hostinfo,"file","targets");//in the hostinfo put file target which contains all host names
sprintf(soft_limmit,"0:%d,",num_hosts);//sprintf stands for “String print”. works just like printf() but instead of sending output to console it returns the formatted string.the function writes the data in the string pointed to by str and returns the number of characters written to str

MPI_Info_set(hostinfo,"soft","soft_limmit");

MPI_Comm_spawn("pcp_slave",MPI_ARGV_NULL,num_hosts,hostinfo,0,MPI_COMM_SELF,&pcpslaves,MPI_ERRCODES_IGNORE);

MPI_Info_free(&hostinfo);//free memory
MPI_Intercomm_merge(pcpslaves ,0 , &all_processes);//merge both communicators for pcp slaves and all process


//middle master part of the copy program

strcpy(outfilename,argv[3]);//copy string pointed by source to destination--->//ww
if((infd =open(argv[2],O_RDONLY))==-1){//attempt to open an input file and when it fails we tell the slaves to exit immmediately.

fprintf(stderr,"input %s doesnot exist\n",argv[2]);//function is same as printf() but instead of writing data to the console, it writes formatted data into the file.stder
sprintf(controlmsg,"exit");// controlmsg(first argument) is the pointer to the target string)-->controlmsg
//sender buffer
MPI_Bcast(controlmsg,CMDSIZE,MPI_CHAR,0,all_processes);//broadcast msg to all parent processes in communicator called all_processes
MPI_Finalize();//close MPI
return -1;

}
else{
sprintf(controlmsg,"ready");//if the file is opened succefully i.e print ready
MPI_Bcast(controlmsg,CMDSIZE,MPI_CHAR,0,all_processes);//send a msg to the all processes (slaves )that the file is ready
    }

MPI_Bcast(outfilename,MAXPATHLEN,MPI_CHAR,0,all_processes);
if((outfd= open(outfilename,O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU))==-1)//every process tries to read the file  
   mystatus=-1;//if one process fails to read the file mystatus=-1
else
mystatus=0;//if it reads the file mystatus=0
MPI_Allreduce(&mystatus,&allstatus,1,MPI_INT,MPI_MIN,all_processes);//combines /reduces both statuses(mystatus=-1&mystatus=0) to one status allstatus of all processes:if any process fails to open the file other processes will know because it will return -1 and they will all return (allstatus==-1)"file could not be opened"

if(allstatus==-1){

fprintf(stderr,"output file %s could not be opened\n",outfilename);
MPI_Finalize();//end MPI
return 1;

}



}


