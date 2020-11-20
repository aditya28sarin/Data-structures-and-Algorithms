#include<bits/stdc++.h>
using namespace std;


void strCopy(string &s1, string &s2)
{
    for(int i=0;i<s1.length();i++)
    {
        s2[i]=s1[i];
    }

}


void myCopy(char s1[], char s2[]) 
{ 
    int i = 0; 
    for (i=0; s1[i] != '\0'; i++) 
       s2[i] = s1[i]; 
    s2[i] = '\0'; 
} 
  

int main()
{
    char s1[100]="Aditya";
    char s2[100]="Sarin";
    
    myCopy(s1,s2);

    cout<<s2;

}