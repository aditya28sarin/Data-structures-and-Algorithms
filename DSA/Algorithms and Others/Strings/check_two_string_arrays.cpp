// Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

// A string is represented by an array if the array elements concatenated in order forms the string.

// Example 1:

// Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
// Output: true
// Explanation:
// word1 represents string "ab" + "c" -> "abc"
// word2 represents string "a" + "bc" -> "abc"
// The strings are the same, so return true.



-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
          string sum1="";
        string sum2="";
         int i=0,j=0;
        while(i<word1.size())
        {
                sum1=sum1+word1[i];
                i++;
        }
            
        while(j<word2.size())
        {
            sum2=sum2+word2[j];
            j++;
        }
        
        
        if(sum1.length()!=sum2.length())
                return false;
        
         i=0,j=0;
        bool flag=true;
        while(i<sum1.length())
        {
            if(sum1[i]!=sum2[i])
                flag=false;
            i++;
        }
     
        return flag;
    }
};