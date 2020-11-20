// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;
vector<int> SortBinaryArray(vector<int> binArray);


 // } Driver Code Ends


//User function template for C++

// binArray is an array that consists only 0s and 1s
// return sorted binary array 
vector<int> SortBinaryArray(vector<int> binArray)
{
    int count=0;
    int n=binArray.size();
   for(int i=0;i<n;i++)
   {
       if(binArray[i]==0)
       {
           count++;
       }
   }
   
   for(int i=0;i<n;i++)
   {
       if(count>0)
       {
           binArray[i]=0;
           count--;
       }
       else
       {
           binArray[i]=1;
       }
   }
   
   return binArray;
}


// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> binArray(n);
	    
	    for(int i = 0; i  < n; i++)
	      cin>>binArray[i];
	      
	  	vector<int> result = SortBinaryArray(binArray);
	  	for(int i=0; i<n; i++)
	  	    cout<<result[i]<<" ";
	      
	    cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends



  //alternative soln
  // C++ program to sort a binary array in one pass 
// #include <bits/stdc++.h> 
// using namespace std; 

// /*Function to put all 0s on left and all 1s on right*/
// void segregate0and1(int arr[], int size) 
// { 
// 	/* Initialize left and right indexes */
// 	int left = 0, right = size-1; 

// 	while (left < right) 
// 	{ 
// 		/* Increment left index while we see 0 at left */
// 		while (arr[left] == 0 && left < right) 
// 			left++; 

// 		/* Decrement right index while we see 1 at right */
// 		while (arr[right] == 1 && left < right) 
// 			right--; 

// 		/* If left is smaller than right then there is a 1 at left 
// 		and a 0 at right. Exchange arr[left] and arr[right]*/
// 		if (left < right) 
// 		{ 
// 			arr[left] = 0; 
// 			arr[right] = 1; 
// 			left++; 
// 			right--; 
// 		} 
// 	} 
// } 

// /* Driver code */
// int main() 
// { 
// 	int cases;
// 	cin>>cases;
	
// 	while(cases--)
// 	{
// 	    int arr_size;
// 	    cin>>arr_size;
	    
// 	    int arr[arr_size];
	    
// 	    for(int i=0;i<arr_size;i++)
	    
// 	    {
// 	        cin>>arr[i];
// 	    }
// 	segregate0and1(arr, arr_size); 

// 	for (int i = 0; i < arr_size; i++) 
// 		cout << arr[i] << " "; 
// 	cout<<endl;
// 	}
	
// 	return 0; 
// } 

// // This is code is contributed by rathbhupendra 
