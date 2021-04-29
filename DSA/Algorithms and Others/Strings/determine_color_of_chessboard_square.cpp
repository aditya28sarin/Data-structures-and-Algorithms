// URL: https://leetcode.com/problems/determine-color-of-a-chessboard-square/

class Solution {
public:
    bool squareIsWhite(string coordinates) {
                
        unordered_set<char> st;
        st.insert('b');
        st.insert('d');
        st.insert('f');
        st.insert('h');
        if((st.find(coordinates[0])!=st.end()) && (coordinates[1]-'0')%2!=0){
            return true;
        }
        
        
        if((st.find(coordinates[0])==st.end()) && (coordinates[1]-'0')%2==0){
            return true;
        }
        
        return false;
    }
};