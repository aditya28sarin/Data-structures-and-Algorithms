// C++ code to reverse a 
// stack using recursion 
#include<bits/stdc++.h> 
using namespace std; 


void reverseUtil(stack<int>& st, int temp){

	if(st.size()==0){
		st.push(temp);
		return;
	}


	int t=st.top();
	st.pop();

	reverseUtil(st,temp);

	st.push(t);
}

void reverse(stack<int>& st){
	if(st.size()==1){
		return;
	}

	int temp = st.top();
	st.pop();

	reverse(st);

	reverseUtil(st,temp);
}

// Driver Code 
int main() 
{ 
	stack<int> st;
	// push elements into 
	// the stack 
	st.push(41); 
	st.push(53); 
	st.push(32); 
	st.push(100);
    st.push(188);
	
	
	// function to reverse 
	// the stack 
	reverse(st); 
	cout<<"Reversed Stack"
		<<endl; 

	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	
	
	
	
} 

