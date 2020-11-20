#include<bits/stdc++.h>
using namespace std;

// Only one traversal is needed, i.e, i from 0 to n and j from n-1 to 0 with at most 2*n steps.
// The above approach will also work for m x n matrix (not only for n x n). Complexity would be O(m + n).
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int m,n,key;
        cin>>m>>n;
               
        cin>>key;

        int arr[m][n];

    //taking input for array    
    for(int i =0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

        int i = 0;
        int j = n-1;
        int flag = 0;
        while(i<m && j>=0)
        {
            if(key==arr[i][j])
            {
                flag=1;
                break;
            }
            if(key>arr[i][j])
            {
                i++;
            }
            if(key<arr[i][j])
            {
                j--;
            }
        }
        if(flag==0)
            cout<<"Element not present"<<endl;
        else
        {
            cout<<"Element present"<<endl;
        }
            
    }
}