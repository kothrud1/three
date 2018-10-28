/*
Adit Srivastava
SE-IT(B)
3134132
*/
#include<iostream>
using namespace std;

template<class T>
class kruskal
{
	struct node
	{
		char a,b;
		T weight;
	};
	struct node store[100],path[100];

	struct set
	{
		T parent,rank;
	}v[100];

	T n,pn,nv;
	public:
	kruskal()
	{
		for(int x = 0;x<100;x++)
		{
			v[x].parent = x;
			v[x].rank = 0;
			
		}
		n = 0;pn = 0;
	}
	void kAlgo()
	{
		sort();pn = 0;int x = 0;
		
		while(pn<nv-1)
		{
			int a = find(getV(store[x].a));
			int b = find(getV(store[x].b));

			if(a!=b)
			{
				path[pn++] = store[x];
				unionC(a,b);
			}
			x++;
		}
	}

	void displayPath()
	{
		cout<<"\n\n"<<endl;
		int cost = 0;
		for(int x = 0;x<pn;x++)
		{
			cout<<path[x].a<<" - "<<path[x].b;
			cout<<"\tw = "<<path[x].weight<<endl;
			cost += path[x].weight;
		}
		cout<<"Cost = "<<cost<<endl;
	}
	
	void create()
	{
		n = 0;
		cout<<"Enter number of vertices = ";
		cin>>nv;
		while(true)
		{

			cout<<"Enter (enter / if you don't want to enter anymore data) = ";
			char temp;
			cin>>temp;
			if(temp!='/')
			{
				store[n].a = temp;
				cin>>store[n].b;
				cout<<"weight = ";
				cin>>store[n].weight;
				n++;
			}
			else
			{
				break;
			}
		}
	}

	void display()
	{
		for(int x = 0;x<n;x++)
		{
			cout<<store[x].a<<" - "<<store[x].b<<endl;
			cout<<"Weight = "<<store[x].weight<<"\n"<<endl;
		}
	}


	private:
	int getV(char a)
	{
		int b;
		if(isupper(a))
		{
			b = a-65;
		}
		else
		{
			b = a-97;
		}
		return b;
	}
	void sort()
	{
		for(int x = 0;x<n;x++)
		{
			int i = x;
			for(int y = 0;y<n;y++)
			{
				if(store[i].weight<store[y].weight)
				{
					struct node temp = store[i];
					store[i] = store[y];
					store[y] = temp;
				}
			}

		}
	}

	int find(int x)
	{
		if(v[x].parent!=x)
		{
			v[x].parent = find(v[x].parent);
		}
		return v[x].parent;
	}

	void unionC(int x,int y)
	{
		if (v[x].rank < v[y].rank)
		{
			v[x].parent = y;
		}
		else if(v[x].rank > v[y].rank)
		{
			v[y].parent = x;
		}
		else
		{
			v[y].parent = x;
			v[x].rank++;
		}
	}
};

int main()
{
	kruskal<int> k;
	int ch;
	do
	{
		cout<<"\n1 - To create graph\n2 - Display Graph\n3 - Fint MST\n4 - Display path and cost"<<endl;
		cout<<"Enter Choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1: k.create();
					break;

			case 2: k.display();
					break;

			case 3: k.kAlgo();
					cout<<"Calculation Successful"<<endl;
					break;

			case 4: k.displayPath();
					break;

			case 5: cout<<"Thanks"<<endl;
					break;

			default: cout<<"Wrong Option"<<endl;
		}
	}while(ch!=5);
}
