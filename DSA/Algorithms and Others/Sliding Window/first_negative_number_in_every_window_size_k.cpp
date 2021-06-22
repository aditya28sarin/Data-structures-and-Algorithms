#include<bits/stdc++.h>
using namespace std;

void firstNegative(vector<int> vt, int k, vector<int>& ans){
    int i=0,j=0;
    vector<int> neg;
    while(j<vt.size()){

        if(vt[j]<0)
            neg.push_back(vt[j]);

        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            if(neg.size()==0){
                ans.push_back(0);
            }
            else{
                ans.push_back(neg[0]);
                if(vt[i]==neg[0]){
                    neg.erase(neg.begin());
                }
            }
            i++;
            j++;
        }
    }
}

int main(){
    vector<int> vt = {12,-1,-7,8,-15,30,16,28};
    int k=3;

    vector<int> ans;
    firstNegative(vt,k,ans);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}