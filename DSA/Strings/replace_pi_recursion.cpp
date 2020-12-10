#include<bits/stdc++.h>
using namespace std;


void replacePi(string str, int i, string &newstr)
{
	if(i==str.length())
	{
		return;
	}

	if(str[i]=='p' && str[i+1]=='i')
	{
		newstr=newstr+"3.14";
	}
	else if(str[i]=='i' && str[i-1]=='p'){
		NULL;
	}
	else
	{
		newstr=newstr+str[i];
	}

	replacePi(str,i+1,newstr);
}


int main(){
	string str;
	cin>>str;
	string newstr="";
	replacePi(str, 0, newstr);

	cout<<newstr;
}