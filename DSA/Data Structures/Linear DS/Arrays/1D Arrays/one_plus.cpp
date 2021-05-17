// URL: https://leetcode.com/problems/plus-one/

class Solution {
public:
vector<int> plusOne(vector<int>& digits) {
        int flag = 1;
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(digits[i]==9)
                digits[i] = 0;
            else
            {
                flag = 0;
                digits[i]++;
                break;
            }
        }
        if(flag) digits.insert(digits.begin(), 1);
        return digits;
    }
};