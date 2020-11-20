#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()

{
    int cases;

    cin>>cases;

    while(cases--)
    {
    string str;

    cin>>str;

    reverse(str.begin(),str.end());

    cout<<str<<endl;

    }

    return 0;

}
