// Given a string calculate length of the string using recursion.

// Examples:

// Input : str = "abcd"
// Output :4

// Input : str = "GEEKSFORGEEKS"
// Output :13


-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

int findLength(string str, int marker)
{
    static int count = 0;
    if(str[marker]=='\0')
        return count;
        
    count++;
    return findLength(str,marker+1);
}

int main()
{
    string str;
    cin>>str;
    
    int len = findLength(str,0);
    
    cout<<len;
    
    return 0;
}