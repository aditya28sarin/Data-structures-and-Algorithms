// URL: https://www.geeksforgeeks.org/program-print-substrings-given-string/

#include<bits/stdc++.h>
using namespace std;

void printSubstrings(string str, string ans)
{
	if(str.length()==0)
	{
		cout<<ans<<endl;
		return;
	}

	char ch = str[0];
	string ros=str.substr(1);

	printSubstrings(ros,ans);
	printSubstrings(ros,ans+ch);
}


int main(){
	string str;
	cin>>str;
	printSubstrings(str, "");
}