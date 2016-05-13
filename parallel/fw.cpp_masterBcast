#include <iostream>
#include <mpi.h>

#include "io_idat.h"
#include "alg.cpp"
#include "etime.cpp"
#define whole_ij whole[j*m+i]
#define whole_ik whole[k*m+i]
#define whole_kj whole[j*m+k]

using namespace std;
int main(int argc, char * argv[])
{
int m,n,mm,*whole,*part;
char outfile[20]="short.idat";

int my_count,*counts,*shift;
int source,dest,tag=50,myid,np, rt_np;
MPI_Status status;
MPI_Group world_group;
MPI_Comm blocks;


read_idat(argv[1],&m,&n,whole);//read data. Since all procs need a whole graph table, it's faster to initialize for all than broadcast by the master.


MPI_Init(&argc, &argv);  
MPI_Comm_rank(MPI_COMM_WORLD, &myid);
MPI_Comm_size(MPI_COMM_WORLD, &np);



//---------------------------perfect square ?-------------------------
rt_np=floor(sqrt(np));
if(rt_np*rt_np!=np){
	if(myid==0)//master
		cerr<<"-------------------------------------------------------------"<<endl
			<<"Number of procs: "<<np<<" is not a perfect square!"<<endl;
	MPI_Finalize();
	exit(-1);}
	//--------------------------------------------------------------------
counts=new int [np];shift=new int [np];shift[0]=0;
//if(m!=8)m=1000;//change this value to crop the graph for debugging
mm=m*m;
my_count=mm/np+((myid<(mm%np))?1:0);
for(int i=0;i<np;i++){
	counts[i]=mm/np+((i<(mm%np))?1:0);
	shift[i+1]=shift[i]+counts[i];
	//if(myid==i)cerr<<"worker id "<<myid<<":\t"<<counts[i]<<" jobs\t"<<shift[i]<<" shift"<<endl;
	MPI_Barrier(MPI_COMM_WORLD);
	}
//^^^^^^^^^^^^^^^^^^^^^distribute blocks^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//if(myid==0){cerr <<"Graph:"<<endl;	show_graph(m,n,whole,0);}
int i,j;
tic();	//start timing
for(int k=0;k<m;k++){
	if(myid==0)cerr<<k<<'\t';
	for(int c=shift[myid];c<shift[myid]+counts[myid];c++){
		
		i=c%m;j=c/m;//calculate FW in its region
		if(whole_ik>=0&&whole_kj>=0)
				if(whole_ij>=0)
					whole_ij=min(whole_ij,whole_ik+whole_kj);
				else if(whole_ij==-1)
					whole_ij=whole_ik+whole_kj;		
		
		}
		MPI_Barrier(MPI_COMM_WORLD);
	
	if(myid!=0){//each proc only broadcast its modified part
		{
			//cerr<<myid<<">"<<id<<'\t';
			MPI_Send(whole+shift[myid],my_count,MPI_INT,0,tag,MPI_COMM_WORLD);	
			}	
		MPI_Barrier(MPI_COMM_WORLD);
		}
	if(myid==0){//master proc recieve the modified part
		for(int id=1;id<np;id++){
			//cerr<<myid<<"<"<<id<<'\t';
			MPI_Recv(whole+shift[id],counts[id],MPI_INT,id,tag,MPI_COMM_WORLD,&status);//they may need to wait for the message later of the loop
			}	
		MPI_Barrier(MPI_COMM_WORLD);
		for(int id=1;id<np;id++){
			MPI_Send(whole,mm,MPI_INT,id,tag,MPI_COMM_WORLD);}
		}
		//MPI_Barrier(MPI_COMM_WORLD);//won't work if use it
		if(myid!=0){
			MPI_Recv(whole,mm,MPI_INT,0,tag,MPI_COMM_WORLD,&status);
			}
		MPI_Barrier(MPI_COMM_WORLD);
		
	
//	MPI_Barrier(MPI_COMM_WORLD);

//	MPI_Group_incl(MPI_COMM_WORLD,my_count[myid],ranks,MPI_Group);//not success using broadcasting.
//	MPI_Bcast(whole+shift[myid],my_count,MPI_INT,myid,MPI_COMM_WORLD);
	//MPI_Barrier(MPI_COMM_WORLD);
}
if(myid==0){//master
	
	toc();	//end timing
	//cerr <<"Shortest path:"<<endl;	show_graph(m,n,whole,0);
	write_idat(m,n,whole,outfile);
	cout<<np<<'\t'<<etime()<<endl;
	}
	
MPI_Finalize();
}
