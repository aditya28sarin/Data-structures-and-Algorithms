#include <bits/stdc++.h>
using namespace std;

int main() {
	
int cases;
cin>>cases;
while(cases--)
{
    int p,t,n;
    float r;
    float val1;

    cin>>p;
    cin>>t;
    cin>>n;
    cin>>r;
    float val =p*(pow((1+r*0.01/n),n*t));
    cout<<floor(val)<<endl;
   
}



	return 0;
}