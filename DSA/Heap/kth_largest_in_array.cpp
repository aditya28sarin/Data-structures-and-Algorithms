class Solution {
public:
    
    
    void heapify(vector<int> &arr, int n, int i)
    {
        int largest=i;
        int l=2*i+1;
        int r=2*i+2;
        
        if(l<n && arr[l]>arr[i])
        {
            largest=l;
        }
        
        if(r<n && arr[r]>arr[largest])
        {
            largest=r;
        }
        
        if(largest!=i)
        {
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
        
    }
    
    
    int findKthLargest(vector<int>& arr, int k) {
         int ans;
	    int n =arr.size();
        for(int i=(n/2)-1;i>=0;i--)
        {
             heapify(arr,n,i);
        }
        int i=n-1;
        while(k>0)
        {
            if(k==1)
            {
                ans=arr[0];
            }
            swap(arr[0],arr[i]);

            heapify(arr,i,0);
            k--;    
             i--;   
        }
        
        return ans;
            
    }
};