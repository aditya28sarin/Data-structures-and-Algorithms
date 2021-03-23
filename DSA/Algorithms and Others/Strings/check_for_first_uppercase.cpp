// Given a string find its first uppercase letter

// Examples :

// Input : geeksforgeeKs
// Output : K

// Input  : geekS
// Output : S

-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;



char findUpperCase(string str, int marker)
{
    if(isupper(str[marker]))
        return str[marker];
        
    return findUpperCase(str, marker+1);
}

int main()
{
    string str;
    cin>>str;
    
    char c = findUpperCase(str,0);
    
    cout<<c;
    
    return 0;
}
