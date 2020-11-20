#include <bits/stdc++.h>
using namespace std;

int luckyOne(int  n)
{
   if(n==1)
return 1;
return 2*luckyOne(n/2);
   
}



int main() {
	int cases;
	cin>>cases;
	
	while(cases--)
	{
	    int  n;
	    cin>>n;
	    
	    int lucky= luckyOne(n);
	    cout<<lucky<<endl;
	}
	return 0;
}