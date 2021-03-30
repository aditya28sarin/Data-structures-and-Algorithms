// URL: https://leetcode.com/problems/possible-bipartition/

class Solution {
public:
    
    
    bool isBi(vector<vector<int>>& dislikes, vector<int>& color, int parent, int N){
        queue<int> q;
        q.push(parent);
        color[parent]=1;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto element: dislikes[curr]){
                if(color[element]==color[curr]){
                    return false;
                }if(color[element]==-1){
                    color[element]=1-color[curr];
                    q.push(element);
                }
            }
        }
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
     
        vector<int> color(N+1,-1);
         int n = dislikes.size();
        vector<vector<int>>adj(N+1);
    
        for(int i=0;i<n;i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        for(int i=1;i<=N;i++){
            if(color[i]==-1){
                if(!isBi(adj,color,i,N)){
                    return false;
                }
            }
        }
        return true;
    }
};