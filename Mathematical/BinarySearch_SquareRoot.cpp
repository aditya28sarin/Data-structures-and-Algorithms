#include<bits/stdc++.h>
using namespace std;


int floorSqrt(int x)
{
    if(x==0 || x==1)
        return x;

    int l=1,r=x;
    int ans;
    while(l<=r)
    {
        int m=l+(r-l)/2;

        if(m*m==x)
            return m;

        if(m*m<x)
        {
            l=m+1;
            ans=m;
        }
        else
        {
            r=m-1;
        }
        
    }
    return ans;
}

int main()
{
    int x = 11; 
    cout << floorSqrt(x) << endl; 
    return 0; 
}