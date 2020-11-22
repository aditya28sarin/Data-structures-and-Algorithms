// You are given an array Arr of size N. Replace every element with the next greatest element (greatest element on its right side) in the array. Also, since there is no element next to the last element, replace it with -1.

// Example 1:

// Input:
// N = 6
// Arr[] = {16, 17, 4, 3, 5, 2}
// Output:
// 17 5 5 5 2 -1
// Explanation: For 16 the greatest element 
// on its right is 17. For 17 it's 5. 
// For 4 it's 5. For 3 it's 5. For 5 it's 2. 
// For 2 it's -1(no element to its right). 
// So the answer is 17 5 5 5 2 -1
// Example 2:

// Input:
// N = 4
// Arr[] = {2, 3, 1, 9}
// Output:
// 9 9 9 -1
// Explanation: For each element except 9 the
// greatest element on its right is 9.
// So the answer is 9 9 9 -1

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)


-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------



#include<bits/stdc++.h>

using namespace std;

class Solution{
public:	
	
	void nextGreatest(int arr[], int n) {
	  
	int max_next=arr[n-1];
	
    arr[n-1]=-1;
        
	  for(int i =n-2;i>=0;i--)
	  {
	      int temp = arr[i];
	      
	      arr[i]=max_next;
	      
	     if(max_next<temp)
	     {
	         max_next=temp;
	     }
	  }
	}
};

int main() {
    int no_of_cases;
    cin >> no_of_cases;
    while (t--) {
        int n, l, r;
        cin >> size_of_array;
        int input_array[size_of_array];
        for (int i = 0; i < size_of_array; i++) {
            cin >> input_array[i];
        }
        Solution ob;
        ob.nextGreatest(input_array, size_of_array);
        for (int i = 0; i < size_of_array; i++) {
            cout << input_array[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
 