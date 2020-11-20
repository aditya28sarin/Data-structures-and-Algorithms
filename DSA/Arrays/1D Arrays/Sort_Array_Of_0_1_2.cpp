// C++ program to sort a binary array in one pass 
#include <bits/stdc++.h> 
using namespace std; 

/*Function to put all 0s on left and all 1s on right*/
void segregate0and1(int arr[], int size) 
{ 
	/* Initialize left and right indexes */
	int left = 0, right = size-1; 

	while (left < right) 
	{ 
		/* Increment left index while we see 0 at left */
		while (arr[left] == 0 && left < right) 
			left++; 

		/* Decrement right index while we see 1 at right */
		while (arr[right] == 1 && left < right) 
			right--; 

		/* If left is smaller than right then there is a 1 at left 
		and a 0 at right. Exchange arr[left] and arr[right]*/
		if (left < right) 
		{ 
			arr[left] = 0; 
			arr[right] = 1; 
			left++; 
			right--; 
		} 
	} 
} 

/* Driver code */
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

// Problems with the above solution.:

//  It requires two traversals of array. 
// This solution may not work if values are a part of the structure. For example, consider a situation where 0 represents Computer Science Stream, 
// 1 represents Electronics and 2 represents Mechanical. We have a list of student objects (or structures) and we want to sort them. 
// We cannot use the above sort as we simply put 0s, 1s, and 2s one by one.