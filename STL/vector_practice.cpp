#include<iostream>
using namespace std;

/*You are required to complete below methods*/

/*inserts an element x at
the back of the vector A */
void add_to_vector(vector<int> &A,int x)
{
	push_back(x);
}

/*sort the vector A in ascending order*/
void sort_vector_asc(vector<int> &A)
{
for(int i=0;i<A.size();i++)
	{
        int k;
	    for(int j=i;j<A.size();j++)
	    {

	    if(A[j]<A[i])
	    {
	        k=A[j];
	        A[j]=A[i];
	        A[i]=k;
        }

	    }


	}


}

/*reverses the vector A*/
void reverse_vector(vector<int> &A)
{
    int temp;

	for(int i=0;i<A.size()/2;i++)
	{

	  temp=A[i];
	  A[i]=A[A.size()-1-i];
	  arr[A.size()-1-i]=temp;


	}

}
}

/*returns the size of the vector  A */
int size_of_vector(vector<int> &A)
{
	return A.size()
}

/*sorts the vector A in descending order*/
void sort_vector_desc(vector<int> &A)
{

for(int i=0;i<A.size();i++)
	{
        int k;
	    for(int j=i;j<A.size();j++)
	    {

	    if(A[j]>A[i])
	    {
	        k=A[j];
	        A[j]=A[i];
	        A[i]=k;
        }

	    }


	}

}

/*prints space separated
elements of vector A*/
void print_vector(vector<int> &A)
{
	for(int i=0;i<A.size();i++)
	{
	    cout<<A[i]<<" ";
	}
}

