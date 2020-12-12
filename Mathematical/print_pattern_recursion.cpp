#include <iostream>
using namespace std;


void printPattern(int n, int val, int &flag)
{
    if(val==n)
    {
        return;
    }
    
    cout<<val<<" ";
    
    if(val>0 && flag==0)
    {
        printPattern(n,val-5,flag);
    }
    else
    {
		flag=1;
    	printPattern(n,val+5,flag);
    }

   
}

int main() {
	int cases;
	cin>>cases;
	while(cases--)
	{
	    int number;
	    cin>>number;
	    

        int val=number-5;
      	int flag=0;
        cout<<number<<" ";
	    printPattern(number,val,flag);
	    cout<<number<<endl;
	}
	return 0;
}