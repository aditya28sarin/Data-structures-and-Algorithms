// URL:https://www.geeksforgeeks.org/move-all-occurence-of-letter-x-from-the-string-s-to-the-end-using-recursion/

#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string str, int &count)
{
	if(str.length()==0)
	{
		return "";
	}
	char ch = str[0];

	string ans = removeDuplicates(str.substr(1),count);

	if(ch=='x')
	{
		return ans + ch;
	}
		
	return ch + ans;
}

int main(){
	string str;
	cin>>str;
	int count=0;
	str = removeDuplicates(str, count);
	
	cout<<str;
}