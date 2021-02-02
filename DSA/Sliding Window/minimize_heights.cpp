// URL: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        vector<pair<int,int>> v;
        vector<int> vis(n);
        
        for(int i = 0; i<n; i++){
            if(arr[i]-k >= 0){
                v.push_back({arr[i]-k, i});
            }
            v.push_back({arr[i]+k, i});
        }
        
        sort(v.begin(), v.end());
        int ele = 0;
        int left = 0;
        int right = 0;
        
        while(ele<n && right < v.size()){
            if(vis[v[right].second] == 0){
                ele++;
            }
            vis[v[right].second]++;
            right++;
        }
        
        int ans = v[right-1].first - v[left].first;
        
        while(right<v.size()){
            if(vis[v[left].second]==1){
                ele--;
            }
            vis[v[left].second]--;
            left++;
            
            
            while(ele<n && right < v.size()){
                if(vis[v[right].second] == 0){
                    ele++;
                }
                vis[v[right].second]++;
                right++;
            }
            
            if(ele==n){
                ans = min(ans, v[right-1].first - v[left].first);
            }
            else{
                break;
            }
        }
        
        return ans;
    }
};