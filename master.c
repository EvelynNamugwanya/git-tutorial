/* pcp from the Scalable Unix Tools,in MPI-2*/
#include "mpi.h"
#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#define BUFSIZE 256*1024
#define CMDSIZE 80

int main(int argc,char*argv[]){

int  num_hosts,mystatus,allstatus,done,numread,infd,outfd;
char outfilename[MAXPATHLEN],controlmsg[CMDSIZE];
char soft_limmit[20];
MPI_Info hostinfo;
MPI_Comm pcpslaves,all_processes;

MPI_Int(&argc,&argv);
 
makehostlist(argv[1],"targets",&num_hosts);//PASSES OUT THE FIRST ARGUMENT & WRITES OUT AHOSTFILE(w/c is understood by MPI_Comm_Spawn via MPI_Info_set------->hostinfo ) CALLED "targets"(2nd argument),and number of hosts
MPI_Info_create(&hostinfo);//address to host info
MPI_Info_set(hostinfo,"file","targets");//in the hostinfo put file target which contains all host names
sprintf(soft_limit,"0:%d,",num_hosts);//sprintf stands for “String print”. works just like printf() but instead of sending output to console it returns the formatted string.he function writes the data in the string pointed to by str and returns the number of characters written to str
MPI_Ifo_set(hostinfo,"soft","soft_limmit")
MPI_Comm_Spawn("pcp_slave",MPI_ARGV_NULL,num_hosts,hostinfo,0,MPI_COMM_SELF,&pcpslaves,MPI_ERRCODES_IGNORE);
MPI_Info_free(&hostinfo);//free memory
MPI_Intercomm_merge(pcpsalaves ,0 , &all processes);)//merge both communicators for pcp slaves and all process


//begining the master of the copy program

strcpy(outfile,argv[3]);//copy string pointed by source to destination
if((infd =open(argv[2],O_RDONLY))==-1){

fprintf(stderr,"input %s doesnot exist\n",argv[2]);//function is same as printf() but instead of writing data to the console, it writes formatted data into the file.stder
sprintf(controlmsg,"exit");// controlmsg(first argument) is the pointer to the target string)-->controlmsg
//sender buffer
MPI_Bcast(controlmsg,CMDSIZE,MPI_CHAR,0,all_processes);//broadcast msg to all parent processes in communicator called all_processes
MPI_Finalize();//close MPI
return -1;

}
else{
sprintf(controlmsg,"ready");
MPI_Bcast(controlmsg,CMDSIZE,MPI_CHAR,0,all_processes);//reciver buffer
    }

MPI_Bcast(outfilename,MAXPATHLEN,MPI_CHAR,0,all_processes);
if((outfd= open(outfilename,O_Create|O_WRONLY|O_TRUNC,S_IRWXU))==-1)
   mystatus=-1;
else
mystatus=0;
MPI_Allreduce(&mystatus,&allstatus,1,MPI_INT,MPI_MIN,all processes);
if(allstatus==-1){

fprintf(stderr,"output file %s could not be opened\n",outfilename);
MPI_Finalize();
return 1;

}



}



