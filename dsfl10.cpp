#include<iostream>
#include<stdlib.h>
using namespace std;

class graph
{
int g[20][20];

public:

graph()
{
}

void readgraph(int n)					//input connected nodes of graph
{							// and create adjacency matrix

	int i,j,c,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)	
		{
			if(i==j)
			g[i][j]=0;
			else 
			g[i][j]=99;
		}
	
	}
	cout<<"\n\t enter the nodes";
	do
	{
		cout<<"\n\t enter from node\t to node\t weight\n\t ";
		cin>>i;
		cout<<"\t ";
		cin>>j;
		cout<<"\t ";
		cin>>k;
		g[i][j]=k;
		g[j][i]=k;
		cout<<"\n\t add more nodes??\t 0 for yes\n\t ";
		cin>>c;
	}while(c==0);

}

							
void printgraph(int n)					//print adjacency matrix
{
        int i,j;
	for(i=0;i<n;i++)
	{
		cout<<"\n";
		for(j=0;j<n;j++)
		{
		cout<<"\t "<<g[i][j];
		}

	}

}

void prims(int n,int s)
{
int pass,min,temp,sum=0;
int i,j,k,l,m;
int visited[n];

for(i=0;i<n;i++)					//initialise visited array
{
	visited[i]=0;
}

	visited[s]=1;

	for(pass=0;pass<n-1;pass++) 			//n-1 passes as starting vertex already selected
	{
		min=99;
		for(i=0;i<n;i++)			//loop for checking next nearest node from all the visited nodes
		{	
			
			temp=99;
			if(visited[i]==1)
			{
				for(j=0;j<n;j++)	//loop for checking next nearest point from selected node
				{
					if(g[i][j]<temp && visited[j]==0)
					{
						temp=g[i][j];
						k=j;
					}
				}	
			
				if(min>temp)
				{
				min=temp;
				l=i;
				m=k;
				}
			}	
	
		}
		sum=sum+min;
		visited[l]=1;
		visited[m]=1;
		cout<<"\n\t from node"<<l<<"to node"<<m;
	
	}

cout<<"\n\t minimum cost of spanning tree = "<<sum<<"\n\t ";
}

};

int main()
{
	int n,ch,s;
	graph g1;

	cout<<"\n\t enter number of nodes\n\t ";
	cin>>n;
	g1.readgraph(n);
	g1.printgraph(n);
	cout<<"\n\t enter starting vertex\n\t ";
	cin>>s;
	g1.prims(n,s);

	return 0;
}




