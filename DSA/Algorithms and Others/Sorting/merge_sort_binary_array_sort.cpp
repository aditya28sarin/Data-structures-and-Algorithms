// Given a binary array, sort it using one traversal and no extra space.

// Examples :

// Input : 1 0 0 1 0 1 0 1 1 1 1 1 1 0 0 1 1 0 1 0 0 
// Output : 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1
// Explanation: The output is a sorted array of 0 and 1

// Input : 1 0 1 0 1 0 1 0 
// Output : 0 0 0 0 1 1 1 1
// Explanation: The output is a sorted array of 0 and 1

-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------


// method 1
#include <bits/stdc++.h> 
using namespace std;
vector<int> SortBinaryArray(vector<int> binArray);


// binArray is an array that consists only 0s and 1s and returns sorted binary array 
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


int main() {
	int no_of_cases;
	cin>>no_of_cases;
	
	while(no_of_cases--)
	{
	    int size_of_array;
	    cin>>size_of_array;
		
	    vector<int> binArray(n);
	    
	    for(int i = 0; i  < size_of_array; i++)
	      cin>>binArray[i];
	      
	  	vector<int> result = SortBinaryArray(binArray);
	  	for(int i=0; i<size_of_array; i++)
	  	    cout<<result[i]<<" ";
	      
	    cout<<endl;
	}
	return 0;
}


//method 2

#include <bits/stdc++.h> 
using namespace std; 

/*Function to put all 0s on left and all 1s on right*/
void segregate0and1(int arr[], int size) 
{ 
	
	int left = 0, right = size-1; 

	while (left < right) 
	{ 
		
		while (arr[left] == 0 && left < right) 
			left++; 

		
		while (arr[right] == 1 && left < right) 
			right--; 

		if (left < right) 
		{ 
			arr[left] = 0; 
			arr[right] = 1; 
			left++; 
			right--; 
		} 
	} 
} 

int main() 
{ 
	int cases;
	cin>>cases;
	
	while(cases--)
	{
	    int arr_size;
	    cin>>arr_size;
	    
	    int arr[arr_size];
	    
	    for(int i=0;i<arr_size;i++)
	    
	    {
	        cin>>arr[i];
	    }
	segregate0and1(arr, arr_size); 

	for (int i = 0; i < arr_size; i++) 
		cout << arr[i] << " "; 
	cout<<endl;
	}
	
	return 0; 
} 

