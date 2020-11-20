
#include <bits/stdc++.h>
using namespace std;

int main() {
	int cases;
	
	cin>>cases;
	
	while(cases--)
	{
	    string str1;
	    cin>>str1;
	    
	    string str2;
	    stack<char> st;
	    int i=0;
	    while(i<str1.length())
	    {
	        if(str1[i]=='.')
	        {
	            while(!st.empty())
	            {
	                str2.push_back(st.top());
	                st.pop();
	            }
	            str2.push_back('.');
	        }
	        else
	            st.push(str1[i]);
            i++;
	    }
	    
	    
        while(!st.empty())
        {
            str2.push_back(st.top());
            st.pop();
        }
	    
	    cout<<str2<<endl;
	}
	return 0;
}