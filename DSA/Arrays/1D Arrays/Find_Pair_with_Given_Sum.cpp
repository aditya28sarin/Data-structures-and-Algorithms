#include<bits/stdc++.h>
using namespace std;



int pairsInSortedRotated(int arr[], int n, int sum)
{
    int i,l,r,cp=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]>arr[i+1])
            break;
    }

            r=i;
            l=(i+1)%n;

        while(l!=r)
        {

            if(arr[l]+arr[r]==sum)
            {
                cp++;

                if(l==(r-1+n)%n)
                    return cp;

                l=(l+1)%n;
                r=(r-1+n)%n;
            }

            if(arr[l]+arr[r]<sum)
            l=(l+1)%n;
            else
            {
                r=(n+r-1)%n;
            }
            
        }
        return cp;
    
}




int main() 
{ 
    int arr[] = {11, 15, 6, 7, 9, 10}; 
    int sum = 16; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    cout << pairsInSortedRotated(arr, n, sum); 
      
    return 0; 
}  