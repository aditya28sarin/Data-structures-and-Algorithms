// URL: https://leetcode.com/problems/add-to-array-form-of-integer/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& a, int k) {
        int n=a.size();
        reverse(a.begin(), a.end());
        int i=0, carry=0;
        while(k>0 || i<n){
            if(i<n){
                a[i]=a[i]+(k%10)+carry;
                carry=a[i]/10;
                a[i]%=10;
                i++;
            } else{
                a.push_back((k%10)+carry);
                carry=a.back()/10;
                a.back()%=10;
            }
           k/=10;
        }
        while(carry>0){
            a.push_back((carry%10));
            carry=a.back()/10;
            a.back()%=10;
        }
        reverse(a.begin(), a.end());
        return a;
    }
};