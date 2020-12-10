// URL: https://www.geeksforgeeks.org/mobile-numeric-keypad-problem/
#include<bits/stdc++.h>
using namespace std;


string keypad []={"","","abc","def","ghi","jkl","mno","pqr","stu","vwz"};


void keypadCombinations(string str, string ans)
{
	if(str.length()==0)
	{
		cout<<ans<<endl;
		return; 
	}
		char ch=str[0];
		string code = keypad[ch-'0'];
		string ros = str.substr(1);

		for(int i=0;i<code.length();i++)
		{
			keypadCombinations(ros, ans +code[i]);
		}
}


int main(){

	keypadCombinations("23", "");
}