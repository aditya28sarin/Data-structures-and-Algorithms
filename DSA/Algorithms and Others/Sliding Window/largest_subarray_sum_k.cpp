#include<bits/stdc++.h>
using namespace std;


int largestSubarray(vector<int> vt, int ip_sum){
    int i=0,j=0;
    int mx=INT_MIN;
    int sum=0;
    while(j<vt.size()){
        sum=sum+vt[j];

        if(sum<ip_sum){
            j++;
        }

        if(sum==ip_sum){
            mx= max(mx,j-i+1);
            j++;
        }

        if(sum>ip_sum){
            while(sum>ip_sum){
                sum=sum-vt[i];
                i++;
            }
            j++;
        }
    }

    return mx;

}

int main(){
    vector<int> vt = {4,1,1,1,2,3,5};
    int ip_sum=8;

    cout<<largestSubarray(vt,ip_sum);
}