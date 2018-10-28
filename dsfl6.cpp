/*
Adit Srivastava
SE-IT(B)
3134132
*/
#include<iostream>
#include<cstring>
using namespace std;

class facebook
{
	struct node
	{
		node* link[100];
		string dob;
		int no_cmt;
		int unqID;
		int linkC;
		bool visit;
	};

	struct queue
	{
		node* data;
		queue* next;
	};
	struct queue *f,*r;
	struct node *head[100];
	int nUser;int unqID;
	public:
	facebook()
	{
		for(int x = 0;x<100;x++)
		{
			head[x] = NULL;
		}
		nUser = 0;
		unqID = 1000;
		f = r = NULL;
	}

	void create()
	{
		cout<<"Enter number of user data who's data you want to enter"<<endl;
		int tnUser;
		cin>>tnUser;

		for (int x = 0; x < tnUser; x++)
		{
			head[nUser] = new node;
			head[nUser]->unqID = unqID;
			unqID++;
			cout<<"Enter Details for User "<<head[nUser]->unqID<<endl;
			cout<<"Enter the number of comment = ";
			cin>>head[nUser]->no_cmt;
			cout<<"Enter the Date Of Birth(DDMMYYYY) = ";
			cin>>head[nUser]->dob;
			head[nUser]->linkC = 0;
			head[nUser]->visit = false;
			nUser++;
		}
	}

	void linkFriends()
	{
		cout<<"Enter the unique ID of the user"<<endl;
		int id;
		cin>>id;
		node* user = search(id);
		if(user!=NULL)
		{
			cout<<"Enter the number of friends the user have = ";
			int friendC;
			cin>>friendC;
			for(int x = 0;x<friendC;x++)
			{
				cout<<"Enter the unique ID of the friend "<<(x+1)<<endl;
				int tID;
				cin>>tID;
				node* temp = search(tID);
				if(temp!=NULL)
				{
					int c = user->linkC;
					user->link[c] = temp;
					c++;
					user->linkC = c;
				}
				else
				{
					cout<<"User does not exists\nEnter correct data"<<endl;
					x--;
				}
			}
		}
		else
		{
			cout<<"User does not exists"<<endl;
		}
	}

	void find_most_no_Friends()
	{
		int index = 0;
		for(int x = index+1;x<nUser;x++)
		{
			if(head[index]->linkC<head[x]->linkC)
			{
				index = x;
			}
		}

		cout<<"User with most number of friends"<<endl;
		cout<<"User = "<<head[index]->unqID<<endl;
		cout<<"Number of Friends = "<<head[index]->linkC<<endl;
	}

	void find_most_no_comments()
	{
		int index = 0;
		for(int x = index+1;x<nUser;x++)
		{
			if(head[index]->no_cmt<head[x]->no_cmt)
			{
				index = x;
			}
		}

		cout<<"User with most number of comments"<<endl;
		cout<<"User = "<<head[index]->unqID<<endl;
		cout<<"Number of Comments = "<<head[index]->no_cmt<<endl;
	}

	void birthByMonth()
	{
		cout<<"Enter the Month(First 3 characters of the month in lower case) = ";
		string month;
		cin>>month;bool flag = false;
		cout<<"Users by Month Of Birth("<<month<<")"<<endl;
		for(int x = 0;x<nUser;x++)
		{
			string temp = getMonth(head[x]->dob);
			if( month.compare(temp) == 0 )
			{
				cout<<"User = "<<head[x]->unqID<<endl;
				flag = true;
				cout<<"Date Of Birth = "<<head[x]->dob<<endl;
			}
		}
		if(!flag)
		{
			cout<<"No user born in this month"<<endl;
		}
	}

	void dfs()
	{
		for(int x = 0;x<nUser;x++)
		{
			if(head[x]->linkC!=0)
			{
				mDFS(head[x]);

			}
		}
		resetVisit();
	}

	void bfs()
	{
		for(int x = 0;x<nUser;x++)
		{
			if(head[x]->linkC!=0)
			{
				if(!head[x]->visit)
				{
					mBFS(head[x]);
				}
			}
		}
		resetVisit();
	}

	private:
	void mBFS(node* b)
	{
		enQueue(b);
		b->visit = true;

		while(!isEmpty())
		{
			node* temp = deQueue();
			cout<<"User = "<<temp->unqID<<endl;

			for(int x = 0;x<temp->linkC;x++)
			{
				if(!temp->link[x]->visit)
				{
					temp->link[x]->visit = true;
					enQueue(temp->link[x]);
				}
			}
		}
	}


	void mDFS(node* u)
	{
		if(!u->visit)
		{
			cout<<"User = "<<u->unqID<<endl;
			u->visit = true;
		}
		for(int x = 0;x<u->linkC;x++)
		{
			if(!u->link[x]->visit)
			{
				mDFS(u->link[x]);
			}
		}
	}

	void resetVisit()
	{
		for(int x = 0;x<nUser;x++)
		{
			head[x]->visit = false;
		}
		f = r = NULL;
	}


	node* search(int findID)
	{
		int min = 0,max = nUser,mid;
		while(min<=max)
		{
			mid = (min+max)/2;
			if(head[mid]->unqID==findID)
			{
				return head[mid];
			}
			else if(head[mid]->unqID<findID)
			{
				min = mid+1;
			}
			else
			{
				max = mid-1;
			}
		}
		return NULL;
	}
	string getMonth(string dob)
	{
		int m = 0;
		for(int x = 2;x<4;x++)
		{
			char temp = dob.at(x);
			if(temp=='1' && x==2)
			{
				m = m+(temp-48);//48 is the ascii of 0
			}
			else if(x==3 && (dob.at(x-1)=='0' || dob.at(x-1)=='1'))
			{
				m = (m*10)+(temp-48);
			}
		}

		switch(m)
		{
			case 1: return "jan";
			case 2: return "feb";
			case 3: return "mar";
			case 4: return "apr";
			case 5: return "may";
			case 6: return "jun";
			case 7: return "jul";
			case 8: return "aug";
			case 9: return "sep";
			case 10: return "oct";
			case 11: return "nov";
			case 12: return "dec";
		}
		return "";
	}


	void enQueue(node *en)
	{
		if(isEmpty())
		{
			f = new queue;
			f->data = en;
			f->next = NULL;
			r = f;
		}
		else
		{
			r->next = new queue;
			r = r->next;
			r->data = en;
			r->next = NULL;
		}
	}

	node* deQueue()
	{
		if(!isEmpty())
		{
			node* temp = f->data;
			f = f->next;
			return temp;
		}
		return NULL;
	}

	bool isEmpty()
	{
		if(f==NULL)
		{
			return true;
		}
		return false;
	}
};

int main()
{
	facebook fb;

	cout<<"===========Facebook==========="<<endl;
	int ch;
	do
	{
		cout<<"1 - Make Entry\n2 - Add Friends\n3 - User with most friends"<<endl;
		cout<<"4 - User with most comments\n5 - Get Users by birth month\n6 - Display using DFS"<<endl;
		cout<<"7 - Display uisng BFS\n8 - Exit"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1: fb.create();
					break;

			case 2: fb.linkFriends();
					break;

			case 3: fb.find_most_no_Friends();
					break;

			case 4: fb.find_most_no_comments();
					break;

			case 5: fb.birthByMonth();
					break;

			case 6: cout<<"Display using DFS"<<endl;
					fb.dfs();
					break;

			case 7: cout<<"Display using BFS"<<endl;
					fb.bfs();
					break;

			case 8: cout<<"Thanks"<<endl;
					break;

			default: cout<<"\nWrong Option"<<endl;
		}
	}while(ch!=8);
	return 0;
}
