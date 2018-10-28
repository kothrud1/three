/*
 * dsfl8.cpp
 *
 *  Created on: 22-Feb-2017
 *      Author: lab1-13
 */

#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
#define INFINITY 999;

class graph
{
	char vnames[10][10];
	int nodes,cost[10][10];
	int predecessor[15],distance[15];
    bool mark[15];
    int source;
	public:
	graph();
	int position(char s[10]);
	void create_graph();
	void display();
	        void initialize();
	        int getClosestUnmarkedNode();
	        void calculateDistance();
	        void output();
	                void printPath(int);
};

graph::graph()
{
	nodes=0;
	for(int i=0;i<10;i++)
	for(int j=0;j<10;j++)
	{
		if(i==j)
		cost[i][j]=0;
		else
		cost[i][j]=999;
	}
}

void graph::create_graph()
{
	char ans,start[10],end[10];
	int wt,i,j;
	cout<<"Enter no of nodes:";
	cin>>nodes;
	cout<<"\n Enter vertex name: ";
	for(i=0;i<nodes;i++)
	{cin>>vnames[i];
	}
	do
	{
		cout<<"Enter start nd end points of the edge: ";
		cin>>start>>end;
		cout<<"Enter the weight: ";
		cin>>wt;
		i=position(start);
		j=position(end);
		cost[j][i]=cost[i][j]=wt;
		cout<<"\n more edges";
		cin>>ans;
	}
	while(ans=='y'||ans=='Y');
	cout<<"Enter the source vertex\n";
	            cin>>source;
	            while((source<0) && (source>nodes-1)) {
	                cout<<"Source vertex should be between 0 and"<<nodes-1<<endl;
	                cout<<"Enter the source vertex again\n";
	                cin>>source;
	            }
}

void graph::display()
{
	int i,j;
	cout<<"\n Adjacency matrix\n\t";
	for(i=0;i<nodes;i++)
	cout<<"\t"<<i;
	for(i=0;i<nodes;i++)
	{
		cout<<"\n\t"<<i;
		for(j=0;j<nodes;j++)
		cout<<"\t"<<cost[i][j];
	}
	cout << "\n";
}

int graph::position(char s[10])
{
	int i;
	for(i=0;i<10;i++)
	if(strcmp(vnames[i],s)==0)
	break;
	return i;
}

void graph::initialize(){
            for(int i=0;i<nodes;i++) {
                mark[i] = false;
                predecessor[i] = -1;
                distance[i] = INFINITY;
            }
            distance[source]= 0;
        }


        int graph::getClosestUnmarkedNode(){
            int minDistance = INFINITY;
            int closestUnmarkedNode;
            for(int i=0;i<nodes;i++) {
                if((!mark[i]) && ( minDistance >= distance[i])) {
                    minDistance = distance[i];
                    closestUnmarkedNode = i;
                }
            }
            return closestUnmarkedNode;
        }


        void graph::calculateDistance(){
            initialize();

            int closestUnmarkedNode;
            int count = 0;
            while(count < nodes) {
                closestUnmarkedNode = getClosestUnmarkedNode();
                mark[closestUnmarkedNode] = true;
                for(int i=0;i<nodes;i++) {
                    if((!mark[i]) && (cost[closestUnmarkedNode][i]>0) ) {
                        if(distance[i] > distance[closestUnmarkedNode]+cost[closestUnmarkedNode][i]) {
                            distance[i] = distance[closestUnmarkedNode]+cost[closestUnmarkedNode][i];
                            predecessor[i] = closestUnmarkedNode;
                        }
                    }
                }
                count++;
            }
        }


        void graph::printPath(int node){
            if(node == source)
                cout<<(char)(node + 97)<<"..";
            else if(predecessor[node] == -1)
                cout<<"No path from “<<source<<”to "<<(char)(node + 97)<<endl;
            else {
                printPath(predecessor[node]);
                cout<<(char) (node + 97)<<"..";
            }
        }


        void graph::output(){
            for(int i=0;i<nodes;i++) {
                if(i == source)
                    cout<<(char)(source + 97)<<".."<<source;
                else
                    printPath(i);
                cout<<"->"<<distance[i]<<endl;
            }
        }
	int main()
	{
	graph sp;
	sp.create_graph();
	sp.display();
	 sp.calculateDistance();
	            sp.output();
	return 0;
	}




