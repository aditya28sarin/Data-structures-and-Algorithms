void print(list<int> &A)
{
	list <int> :: iterator it1=A.begin();

	if(A.empty())
	cout<<"-1"<<endl;
	else
	{
	while(it1!=A.end())
	{
	    cout<<*it1<<" ";
	    it1++;
	}
	cout<<'\n';
	}
}

void remove_from_back(list<int> &A)
{
   A.pop_back();
}

void remove_from_front(list<int> &A)
{

   A.pop_front();
}


void add_to_list(list<int> &A,int x)
{
	A.push_back(x);
}


void sort_list(list<int> &A)
{
	A.sort();
}


void reverse_list(list<int> &A)
{
	A.reverse();
}


int size_of_list(list<int> &A)
{
	A.size();
}


void add_from_front(list<int> &A,int x)
{
	A.push_front(x);
}
