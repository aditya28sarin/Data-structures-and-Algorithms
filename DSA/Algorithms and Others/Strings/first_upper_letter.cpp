#include<bits/stdc++.h>
using namespace std;


char findFirstUppercase(string str)
{
	if(str.length()==0)
		return 0;

	char ch=str[0];
	string ros=str.substr(1);

	if(isupper(ch))
	{
		return ch;
	}

	return findFirstUppercase(ros);
}


int main()
{
	string str;
	cin>>str;

	cout<< findFirstUppercase( str);
}