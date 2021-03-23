//URL: https://leetcode.com/problems/next-greater-element-i/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      vector<int> res(nums1.size(), -1); //to be returned, initialize it with -1.
        stack<int> st;
        unordered_map<int, int> umap;
        for(int i=0; i<nums2.size(); i++)
        {
          
            while(!st.empty() && st.top()<nums2[i])
            {
                umap[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        for(int i=0; i<nums1.size(); i++)
        {
            int ele = nums1[i];
            if(umap.find(ele) != umap.end())
            {
                int nge = umap[ele];
                res[i] = nge; 
            }
                
        }
        
        return res;
        
    }
};
