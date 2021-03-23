// URL: https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
         int n1=arr1.size();
    int n2=arr2.size();
    
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    
    vector<int> ans;
    
    int i=0,j=0;
    while(i<n1 && j<n2){
        if((arr1[i]<arr2[j]) || count(ans.begin(),ans.end(),arr1[i])!=0){
            i++;
        }
        
        else if((arr1[i]>arr2[j]) || count(ans.begin(),ans.end(),arr2[j])!=0){
            j++;
        }
        
        else if((arr1[i]==arr2[j]) && count(ans.begin(),ans.end(),arr1[i])==0){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    
    return ans;
    }
};