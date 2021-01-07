// URL: https://leetcode.com/problems/interleaving-string/

#include<bits/stdc++.h>
using namespace std;

bool checkString(unordered_map<string,bool>  &map,string s1, string s2, string s3, int len1, int len2, int len3, int p1, int p2, int p3)
{
    
    //check for base case
    if(p3==len3)
    {
        if(p1==len1 && p2==len2)
            return true;
        else
            return false;
    }

    string key = to_string(p1)+"*"+to_string(p2)+"*"+to_string(p3);

    //check for calculated value
    if(map.find(key)!=map.end())
        return map[key];


    // 3 cases , case 1: if p1 has reached end of s1
    if(p1==len1)
        return (map[key]= s2[p2]==s3[p3]?checkString(map,s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1):false);


    //case 2: if p2 has reached the end of s2
    if(p2==len2)
        return (map[key]= s1[p1]==s3[p3]?checkString(map,s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1):false);


    // case 3: if both havent reached the4 end of their strings
    bool first = false, second = false;
    if(s1[p1]==s3[p3])
        first = checkString(map,s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1);

    if(s2[p2]==s3[p3])
        second = checkString(map,s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1);

    return map[key]=first || second;

}

bool isInterleave(string s1, string s2, string s3) {
     int len1=s1.length();
     int len2=s2.length();
     int len3=s3.length();
    unordered_map<string,bool> map;
     return checkString(map,s1,s2,s3,len1,len2,len3,0,0,0);
    }

int main()
{
    string str1="aa";
    string str2="bb";
    string res="bbaa";
    cout<<isInterleave(str1,str2,res);
}
