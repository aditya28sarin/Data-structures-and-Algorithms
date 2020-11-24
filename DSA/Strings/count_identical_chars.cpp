#include<bits/stdc++.h>
using namespace std;


int main()  
{  
    string s="geeksforgeeks";
    int n=26;
    int store_char[26]={0};
    
    for(int i=0;i<s.size();i++)
    {
        store_char[int(s[i])-int('a')]=store_char[int(s[i])-int('a')]+1;
    }
    
    for(int i=0;i<26;i++)
    {
        if(store_char[i]!=0)
        {
            cout<<char(i+97)<<" occurs "<<store_char[i]<<" times."<<endl;
        }
    }
    
}  