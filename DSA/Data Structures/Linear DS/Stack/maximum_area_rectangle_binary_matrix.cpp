// URL: https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    
    int largestArea(vector<int>& histogram){
        int n=histogram.size(), area=0;
        stack<int> s;
        
        for(int i=0; i<n; i++){
            while(!s.empty() && histogram[s.top()]>=histogram[i]){
                int top = s.top();
                s.pop();
                
                int start;
                if(s.empty())
                    start = -1;
                else
                    start = s.top();
                    
                
                int curr_area = histogram[top] * (i - start -1);
                area = max(area, curr_area);
            }
            s.push(i);
        }
        
        while(!s.empty()){
            int top = s.top();
            s.pop();

            int start;
            if(s.empty())
                start = -1;
            else
                start = s.top();
            
            int curr_area = histogram[top] * (n - start -1);
            area = max(area, curr_area);
        }
        
        return area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size(), result=0;
        vector<int> histogram(n, 0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1')
                    histogram[j]+=1;
                else
                    histogram[j]=0;
            }
            
            result = max(result, largestArea(histogram));
            cout<<result<<" ";
        }
        return result;
    }
};




//new code 

class Solution {
public:


    vector<int> findNSL(vector<int>& heights, int n){
        vector<int> left;
        stack<pair<int,int>> st;
        int pseudoIndex=-1;
        for(int i=0;i<n;i++){
            if(st.size()==0){
                left.push_back(pseudoIndex);
            }
            else if(st.size()>0 && st.top().first<heights[i]){
                left.push_back(st.top().second);
            }

            while(!st.empty() && st.top().first>=heights[i]){
                st.pop();
            }

            if(st.empty()){
                left.push_back(pseudoIndex);
            }else{
                left.push_back(st.top().second);
            }

            st.push({heights[i],i})
        }

        return left;
    }


    
    vector<int> findNSR(vector<int>& heights, int n){
        vector<int> right;
        stack<pair<int,int>> st;
        int pseudoIndex=n;
        for(int i=n-1;i>=0;i--){
            if(st.size()==0){
                right.push_back(pseudoIndex);
            }
            else if(st.size()>0 && st.top().first<heights[i]){
                right.push_back(st.top().second);
            }

            while(!st.empty() && st.top().first>=heights[i]){
                st.pop();
            }

            if(st.empty()){
                right.push_back(pseudoIndex);
            }else{
                right.push_back(st.top().second);
            }

            st.push({heights[i],i})
        }

        return right;
    }

    int largestRectangleArea(vector<int>& heights) {
    
        int n = heights.size();

        vector<int> left(n), right(n);

        left = findNSL(heights,n);
        right = findNSR(heights,n);

        vector<int> area(n);

        for(int i=0;i<n;i++){
            area[i]=(right[i]-left[i]-1)*heights[i];
        }

        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(area[i]>max){
                max=area[i];
            }
        }
    return max;
    }


    int maxMatrix(vector<vector<int>> matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        for(int j=0;j<m;j++){
            ans.push_back(matrix[0][j]);
        }

        int mx = largestRectangleArea(ans);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    ans.push_back(0);
                }else{
                    ans[j]=ans[j]+matrix[i][j];
                }
            }

            mx = max(mx,largestRectangleArea(vt));
        }
        return mx;
    }
};