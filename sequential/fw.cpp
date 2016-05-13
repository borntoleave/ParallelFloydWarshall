#include <iostream>
#include "io_idat.h"
#include "alg.cpp"
#include "etime.cpp"
#define shortest_ij shortest[j*m+i]
#define shortest_ik shortest[k*m+i]
#define shortest_kj shortest[j*m+k]

using namespace std;
int main(int argc, char * argv[])
{
	int m,n,*shortest;
	char outfile[20]="short.idat";
	read_idat(argv[1],&m,&n,shortest);
	cerr <<"Graph:"<<endl;
	//show_graph(m,n,shortest,0);
	tic();
	seq_FW(m,n,shortest);
	toc();
	cerr <<"Shortest path:"<<endl;
	//show_graph(m,n,shortest,0);
	write_idat(m,n,shortest,outfile);
	cerr<<"\tTime used:";
	cout<<'\t'<<etime()<<endl;
}
