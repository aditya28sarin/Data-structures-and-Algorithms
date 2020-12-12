#include<bits/stdc++.h>
using namespace std;

void printCombinations(string str, string ans)
{
	if(str.length()==0)
	{
		cout<<ans<<endl;
		return;
	}

	char ch=str[0];
	string ros = str.substr(1);

	printCombinations(ros,ans+ch);
	cout<<ans<<endl;
}


int main(){

	printCombinations("123", "");
}