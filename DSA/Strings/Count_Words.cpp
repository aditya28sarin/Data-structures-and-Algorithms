#include <iostream>
using namespace std;

int main() {
	int cases;
	
	cin>>cases;
	
	while(cases--)
	{
	    string str;
	    
	    cin>>str;
	    
	    for(int i=0;i<str.length();i++)
	    {
	        // if(str[i]==' ' || str[i]=='\t')
	        // {
	        //    continue;
	        // }
             cout<<str[i];
	    }
    cout<<endl;
        cout<<str;
	}
	return 0;
}