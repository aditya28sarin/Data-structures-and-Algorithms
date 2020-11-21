class Solution {
public:
    int numJewelsInStones(string J, string S) {
     
        unordered_set <char> st;
        int count=0;
        for(int i=0;i<J.length();i++)
        {
            st.insert(J[i]);
        }
        
        for(int i=0;i<S.length();i++)
        {
            if(st.find(S[i])!=st.end())
            {
                count++;
            }
        }
     return count;   
    }
};