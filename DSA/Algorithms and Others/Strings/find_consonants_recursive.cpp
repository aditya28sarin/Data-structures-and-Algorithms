// Given a string, count total number of consonants in it. A consonant is a English alphabet character that is not vowel (a, e, i, o and u). Examples of constants are b, c, d, f, g, ..

// Examples :

// Input : abc de
// Output : 3
// There are three consonants b, c and d.

// Input : geeksforgeeks portal
// Output : 12

-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------


#include<bits/stdc++.h>
using namespace std;

int findConsonants(string str,int marker)
{
    char ch=toupper(str[marker]);
    static int count=0;
    if(str[marker]=='\0')
        return count;
    
    if(ch!='A' && ch!='E' &&  ch!='I' &&  ch!='O' &&  ch!='U' && ch!=' ')
    {
        count++;
    }
    return findConsonants(str, marker+1);
}

int main()
{
    string str;
    getline(cin,str);
    
    int count = findConsonants(str,0);
    
    cout<<count;
    
    return 0;
}