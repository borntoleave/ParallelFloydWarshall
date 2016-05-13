//This short program shows a certain line in a graph, which can be very helpful for large graphs.
#include <iostream>
#include "io_idat.h"
#include "alg.cpp"

using namespace std;
int main(int argc, char * argv[])
{	
	if(argc!=3){cerr<<"This program shows a certain line in a graph."<<endl
					<<"\tWhen line number is 0, it prints out the whole graph."<<endl
					<<"\t\tFormat: "<<argv[0]<<" <bin file> <line>"<<endl;
				exit(-1);}
	int m,n,*shortest,line;
	line=atoi(argv[2]);
	read_idat(argv[1],&m,&n,shortest);
	show_graph(m,n,shortest,line);
}
