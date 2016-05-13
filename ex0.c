#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mpi.h>
#define MLENGTH 100
int main(int argc, char *argv[])
{
int my_rank,p,source,dest,tag=50;
char message[MLENGTH];
MPI_Status status;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
MPI_Comm_size(MPI_COMM_WORLD,&p);
if(my_rank!=0){
	sprintf(message,"Greetings (%d)",my_rank);
	dest=0;
	MPI_Send(message,strlen(message)+1,MPI_CHAR,dest,tag,MPI_COMM_WORLD);
	}
else{
	for(source=1;source<p;source++){
		MPI_Recv(message,MLENGTH,MPI_CHAR,source,tag,MPI_COMM_WORLD,&status);
		printf("%s\n",message);
		}
	printf("My rank is %d. I'm done.\n",my_rank);
	}
MPI_Finalize();
}
