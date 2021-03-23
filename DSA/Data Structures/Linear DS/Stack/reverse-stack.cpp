// C++ code to reverse a 
// stack using recursion 
#include<bits/stdc++.h> 
using namespace std; 

// using std::stack for 
// stack implementation 
stack<int> st; 

// intializing a string to store 
// result of reversed stack 
string ns; 

// Below is a recursive function 
// that inserts an element 
// at the bottom of a stack. 
int insert_at_bottom(int x) 
{
	if(st.size() == 0) 
	st.push(x); 

	else
	{ 	
		// All items are held in Function Call 
		// Stack until we reach end of the stack 
		// When the stack becomes empty, the 
		// st.size() becomes 0, the above if 
		// part is executed and the item is 
		// inserted at the bottom 
			
		int a = st.top(); 
		st.pop(); 
		insert_at_bottom(x); 

		// push allthe items held in 
		// Function Call Stack 
		// once the item is inserted 
		// at the bottom 
		st.push(a); 
	} 
} 

// Below is the function that 
// reverses the given stack using 
// insert_at_bottom() 
int reverse() 
{ 
	if(st.size()<=0) 
		return 0;
		
		// Hold all items in Function 
		// Call Stack until we 
		// reach end of the stack 
		int x = st.top(); 
		st.pop(); 
		reverse(); 
		
		// Insert all the items held 
		// in Function Call Stack 
		// one by one from the bottom 
		// to top. Every item is 
		// inserted at the bottom 
		insert_at_bottom(x); 
} 

// Driver Code 
int main() 
{ 
	
	// push elements into 
	// the stack 
	st.push(41); 
	st.push(53); 
	st.push(32); 
	st.push(100);
    st.push(188);
	
	
	// function to reverse 
	// the stack 
	reverse(); 
	cout<<"Reversed Stack"
		<<endl; 
	
	// storing values of reversed 
	// stack into a string for display 
	while(!st.empty()) 
	{ 
		int p=st.top(); 
		st.pop(); 
		cout<<p<<" ";
	} 
	
	
} 

// This code is contributed by Gautam Singh 
