#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <mpi.h>

#define shortest_ij shortest[j*m+i]
#define shortest_ik shortest[k*m+i]
#define shortest_kj shortest[j*m+k]
using namespace std;


void show_graph(int m,int n,int *shortest,int line)
{
if (line==0)
	for(int i=0;i<m;i++)
		{for(int j=0;j<n;j++)
 			printf("%6d",shortest_ij);
		 printf("\n");
		}
else
	{
	if (line>m){cerr<<"Line number larger than the dimension!"<<endl;exit(-1);}
	int i=line-1;
	for(int j=0;j<n;j++)
 			printf("%6d",shortest_ij);
		 printf("\n");
		}
}


