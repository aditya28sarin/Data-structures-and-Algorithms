#include<bits/stdc++.h>
using namespace std;

int countAnagrams(string str, string temp){
    unordered_map<char,int> mp;
    int k=temp.length();
    int ans=0;
    
    for(int i=0;i<temp.length();i++){
        mp[temp[i]]++;
    }

    // int count=mp.size();
    
    int i=0,j=0;
    while(j<str.length()){

        mp[str[j]]--;

        if(mp[str[j]]==0){
            mp.erase(str[j]);
        }
        
        if(j-i+1<k){
            j++;
        }

        else if(j-i+1==k){
            
            if(mp.size()==0){
                ans++;
            }

            mp[str[i]]++;

            if(mp[str[i]]==0){
                mp.erase(str[i]);
            }

            i++;
            j++;
        }

    }

    return ans;
}


int main(){
    string str = "forxxorfxaofr";
    string temp="for";

    cout<<countAnagrams(str,temp);
}