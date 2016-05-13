#include <iostream>
#include <fstream>
#include <algorithm>
#define shortest_ij shortest[j*m+i]
#define shortest_ik shortest[k*m+i]
#define shortest_kj shortest[j*m+k]
using namespace std;
void seq_FW(int m, int n, int *shortest)
{
for(int k=0;k<m;k++)
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			{if(shortest_ik>=0&&shortest_kj>=0)
				if(shortest_ij>=0)
					shortest_ij=min(shortest_ij,shortest_ik+shortest_kj);
				else if(shortest_ij==-1)
					shortest_ij=shortest_ik+shortest_kj;
			}
}

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
