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
	int code = ch;
	string ros=str.substr(1);

	printSubstrings(ros,ans);
	printSubstrings(ros,ans+ch);
	printSubstrings(ros,to_string(code));
}


int main(){
	string str;
	cin>>str;
	printSubstrings(str, "");
}