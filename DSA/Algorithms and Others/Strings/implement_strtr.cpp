// URL: https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        
     if(needle == "")
           return 0;
        int len = needle.length();
    
        for(int i=0;i<haystack.length();i++){
            int ptr=0;
            if(haystack[i] == needle[ptr]){
                int j=i;

                int counter=0;
                while(ptr<len && haystack[j] == needle[ptr] ){
                    counter++;
                    ptr++;
                    j++;
                }
                if(counter == len)
                    return i;

                
            }
        }
        return -1;
    }
};