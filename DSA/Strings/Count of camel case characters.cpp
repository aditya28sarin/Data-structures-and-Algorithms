#include <iostream>
using namespace std;



int main() {
	string s;
	int cases,count=0;

        cin>>cases;
	while(cases--)
	{
	 cin>>s;

	 for(int i=0;i<s.length();i++)
	 {
	     if(isupper(s[i]))
	     count++;
	 }

	 cout<<count<<endl;
	 count=0;
	}
	return 0;}
