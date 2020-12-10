// URL:https://practice.geeksforgeeks.org/problems/consecutive-elements/0#

#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string str)
{
	if(str.length()==0)
	{
		return "";
	}
	char ch=str[0];
	string ans = removeDuplicates(str.substr(1));

	if(ch==ans[0])
	{
		return ans;
	}

	return (ch+ans);
}

int main(){

	cout<<removeDuplicates("aaaabbbeeecdddd");
}