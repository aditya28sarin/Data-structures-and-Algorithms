#include <iostream>
using namespace std;

int main() {
	int n;
	int n1[500],n2[500];
	int prod[500];
	cin>>n;
for(int i=0;i<n;i++)
	{
	    cin>>n1[i]>>n2[i];
	    prod[i]=n1[i]*n2[i];

	}

for(int i=0;i<n;i++)
	{
	   cout<<prod[i]<<endl;
	}

	return 0;
}
