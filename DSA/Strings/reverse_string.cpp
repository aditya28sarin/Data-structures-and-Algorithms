class Solution {
public:
    void reverseString(vector<char>& s) {
        int left_ptr=0;
        int right_ptr=s.size()-1;
        char temp_var;
        while(left_ptr<right_ptr)
        {
            swap(s[left_ptr],s[right_ptr]);
            
            left_ptr++;
            right_ptr--;
        }
        
        for(int i=0;i<s.size();i++)
        {
            cout<<s[i]<<" ";
        }
    }
};

//recursive solution 

void stringReverse(string &s, int left, int right)
{
    if(left>=right)
        return;
        
    swap(s[left],s[right]);    
    stringReverse(s,left+1,right-1);
}
