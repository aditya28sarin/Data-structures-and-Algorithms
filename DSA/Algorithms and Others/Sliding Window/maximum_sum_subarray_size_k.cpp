#include<bits/stdc++.h>
using namespace std;

int slidingWindow(vector<int>& vt, int k){

    int i=0,j=0,sum=0;
    int mx=0;
    while(j<vt.size()){

        sum=sum+vt[j];

        if(j-i+1<k){
            j++;
        }

        else if(j-i+1==k){
            mx = max(mx,sum);
            sum=sum-vt[i];
            i++;
            j++;
        }
    }

    return mx;
}


int main(){
    vector<int> vt = {2,5,8,2,9,1};
    int k=3;

    cout<<slidingWindow(vt,k);

}