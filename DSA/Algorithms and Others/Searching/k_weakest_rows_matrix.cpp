// URL: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

#include<bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 


//O(rlogc)
vector<int> binSearch(vector<vector<int>> arr, int k){
    
    vector<pair<int,int>> ans;
    
    int count = 0;
    for(int i=0;i<arr.size();i++){
        int l = 0, r = arr[i].size()-1;
        int i_l = i, i_r = r;
        while(l<=r){
            int m = (r-l)/2 + l;
            
            if(arr[i][0]==0){
                ans.push_back(make_pair(0,0));
                break;
            }
            
            else if (arr[i][r]==1){
                ans.push_back(make_pair(i_r+1,i));
                break;
            }
            
            else if (arr[i][m]==0 && arr[i][m-1]==0)
                r=m-1;
                
            else if (arr[i][m]==0 && arr[i][m-1]==1){
                ans.push_back(make_pair(i_r-m,i));
                break;
            }
            
            else if (arr[i][m]==1 && arr[i][m+1]==1)
                l=m+1;
                
            else if(arr[i][m]==1 && arr[i][m+1]==0){
                ans.push_back(make_pair(m+1,i));
                break;
            }
                
        }
        
    }
    
    sort(ans.begin(),ans.end());
    
    vector<int> res;
    
    for (int i=0; i<k; i++) 
    { 
        res.push_back(ans[i].second); 
    } 
    
    return res;
    }


int main(){

    int r,c;
    cin>>r>>c;

    vector<vector<int>> arr(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            
            cin>>arr[i][j];
        }
    }
    vector<int> ans = binSearch(arr, 2);
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

