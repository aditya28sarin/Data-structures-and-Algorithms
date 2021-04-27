class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char target) {
        
        if(target<arr[0] || target > arr[arr.size()-1]){
            return arr[0];
        }
        
        int l=0;
        int r=arr.size()-1;
        char res;
        while(l<=r){
            int m = l + (r-l)/2;
            
            if(arr[m]<=target){
                l=m+1;
            }
            
            else if(arr[m]>target){
                res=arr[m%arr.size()];
                r=m-1;
            }
        }
        
        return res;
    }
};