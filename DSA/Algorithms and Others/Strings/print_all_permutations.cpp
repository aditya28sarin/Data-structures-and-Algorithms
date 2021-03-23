// URL: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

#include<bits/stdc++.h>
using namespace std;


void printPermutations(string str, string ans){
	if(str.length()==0)
	{
		cout<<ans<<endl;
		return;
	}

	for(int i=0;i<str.length();i++)
	{
		char ch=str[i];
		string ros = str.substr(0,i)+ str.substr(i+1);

		printPermutations(ros,ans+ch);
	}
}

int main(){

	printPermutations("ABC", "");
}


//alternate
void permute(string a, int l, int r)
{ 

    if (l == r) 
        cout<<a<<endl; 
    else
    { 
        for (int i = l; i <= r; i++) 
        { 

            swap(a[l], a[i]); 
 
            permute(a, l+1, r); 

            swap(a[l], a[i]); 
        } 
    } 
} 