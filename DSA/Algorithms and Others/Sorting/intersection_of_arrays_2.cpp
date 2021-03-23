// URL: https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& arr1, vector<int>& arr2) {
            int n1=arr1.size();
    int n2=arr2.size();
    
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    
    vector<int> ans;
    
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            i++;
        }
        
        else if(arr1[i]>arr2[j]){
            j++;
        }
        
        else if(arr1[i]==arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    
    return ans;
    }
};