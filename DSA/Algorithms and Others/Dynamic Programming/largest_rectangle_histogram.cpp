// URL: https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> left(n), right(n);
        
        stack <int> st;
        
        //left to right traversal to keep track of the left limit
        for(int i=0;i<n;i++){
            
            if(st.empty()){
                left[i]=0;
                st.push(i);
            }else{
                
                while(!st.empty() && heights[st.top()]>=heights[i])
                    st.pop();
                
                left[i]=st.empty()?0:st.top()+1;
                st.push(i);
            }
        }
        
        //clearing the stack 
        while(!st.empty()){
            st.pop();
        }
        //right limit
        for(int i=n-1;i>=0;--i){
            if(st.empty()){
                right[i]=n-1;
                st.push(i);
            }else{
                while(!st.empty() && heights[st.top()]>=heights[i])
                    st.pop();
                    
                right[i]=st.empty()?n-1:st.top()-1;
                st.push(i);
            }
        }
        
        //find the max area
        int max_area=0;
        for(int i=0;i<n;i++){
            max_area = max(max_area,heights[i]*(right[i]-left[i]+1));
        }
        
        return max_area;
    }
};






















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
};