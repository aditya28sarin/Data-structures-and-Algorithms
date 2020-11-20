#include<bits/stdc++.h>
using namespace std;


int round(int n)
{
    int a = (n/10)*10;
    
    int b = a+10;

    return(n-a>b-n?b:a);
}


int main()
{
    int n = 999; 
    cout << round(n) << endl; 
    return 0; 
}


// with strings 
int main() {
	int t;cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int n=s.length();
	    if(n==1)
	    {
	        if(s[0]-'0'<6)
	            cout<<"0"<<endl;
	       else
	            cout<<"10"<<endl;
	    }
	    else if(s[n-1]-'0' < 6)
	    {
	        s[n-1]='0';
	        cout<<s<<endl;
	    }
	    else
	    {
	        int x=n-2;
	        s[n-1]='0';
	        while(s[x] == '9' && x>=0)
	        {
	            s[x--]='0';
	        }
	        if(x<0)
	       {
	           s.insert(0,"1");
	       }
	       else
	            s[x]=s[x]+1;
	       cout<<s<<endl;
	    }
	    }
	return 0;
}