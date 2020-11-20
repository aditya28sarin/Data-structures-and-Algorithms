#include <bits/stdc++.h>
using namespace std;


void binarySearch(int arr[], int l, int r,int x)
{
    if(l<=r)
    {
        int mid = l +(r-l)/2;
        
        if(arr[mid]==x && arr[mid-1]!=x)
        {
            int li=mid;
            while(arr[mid]==x)
            {
                mid++;
            }
            int ri=mid-1;
            
            cout<<li<<" "<<ri;
            return;
        }
        
        if(arr[mid]!=x && arr[mid]<x)
            binarySearch(arr,mid+1,r,x);
        
        if((arr[mid]!=x && arr[mid]>x) || (arr[mid]==x && arr[mid-1]==x))
            binarySearch(arr,l,mid-1,x);
            
    }
    else
     cout<<-1;
}





int main() {
	int cases;
	
	cin>>cases;
	
	while(cases--)
	{
	    int n,x;
	    
	    cin>>n>>x;
	    
	    int arr[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    
	   binarySearch(arr,0,n-1,x);
	   
	    cout<<endl;
	}
	
	return 0;
}