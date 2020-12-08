// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

class Solution{   
public:

void countSort(vector<int> &input_array, int array_size)
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


    int median(vector<vector<int>> &matrix, int r, int c){
        vector<int> vt;
        
        for(int i=0;i<r;i++)
        {
            vt.insert(vt.end(),matrix[i].begin(), matrix[i].end());
        }
        
        countSort(vt,vt.size());
        
        return vt[vt.size()/2];
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends