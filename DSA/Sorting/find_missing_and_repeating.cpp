// URL:https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:


void countSort(int input_array[], int array_size)
{
	int max=input_array[0];
	for(int i=0;i<array_size;i++)
	{
		if(input_array[i]>max)
			max=input_array[i];
	}

	int count_array[max+1]={0};

	//filling the count array values
	for(int i=0;i<array_size;i++)
	{
		count_array[input_array[i]]++;
	}

	//modifying the count array
	for(int i=1;i<=max;i++)
	{
		count_array[i]=count_array[i]+count_array[i-1];
	}

	//this is our output array 
	int output_array[array_size];
	for(int i=array_size-1;i>=0;i--)
	{
		output_array[--count_array[input_array[i]]]=input_array[i];
	}

	//putting the final values inside the original array
	for(int i=0;i<array_size;i++)
	{
		input_array[i]=output_array[i];
	}

}

    int *findTwoElement(int *arr, int n) {
        
        countSort(arr,n);
        int res[n+1]={0};
        
        for(int i=0;i<n;i++)
        {
            res[arr[i]]+=1;
        }
        int *ans = new int(2);
        for(int i=0;i<n+1;i++)
        {
            if(res[i]==2)
                ans[0]=i;
            if(res[i]==0 && i!=0)
                ans[1]=i;
        }
        
        return ans;
        
    }
        
        
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
} 