#include<bits/stdc++.h>
using namespace std;


int uniqueCharacter(string str, int k){
    int i=0,j=0;
    unordered_map<char,int> mp;
    mp.clear();
    int mx=-1;
    while(j<str.length()){
        mp[str[j]]++;

        if(mp.size()<k){
            j++;
        }

        if(mp.size()==k){
            mx=max(mx,j-i+1);
            j++;
        }

        if(mp.size()>k){
            while(mp.size()>k){
                mp[str[i]]--;
                if(mp[i]==0){
                    mp.erase(str[i]);
                }
                i++;
            }
            j++;
        }

    }

    return mx;
}

int main(){
    string str="aabacbebebe";
    int k=3;

    cout<<uniqueCharacter(str,k);
}