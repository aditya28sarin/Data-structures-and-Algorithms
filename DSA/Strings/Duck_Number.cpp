#include <iostream>
using namespace std;

int main() {
	int cases;
	
	cin>>cases;
	
	while(cases--)
	{
	   string str;
	   int flag=0;
	   cin>>str;
	    int i=0;
	    while(str[i]=='0')
	        i++;
	   if(str.length()==1)
	    cout<<"NO"<<endl;
	    
	
	    else 
	    {
	        for(i;i<str.length();i++)
	        {
	            if(str[i]=='0')
	                flag=1;
	        }
	        if(flag==1)
	            cout<<"YES"<<endl;
	       else if (flag==0)
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}