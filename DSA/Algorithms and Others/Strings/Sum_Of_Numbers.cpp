#include <bits/stdc++.h>
using namespace std;

int main() {
	int cases;
	cin>>cases;
	queue <int> q;

	while(cases--)
	{
	    string s;
	    cin>>s;
	    
	    int i=0,sum=0,sum1=0,no;
	    while(i<s.length())
	    {
	        if(isdigit(s[i]))
	        {
	            
	            while(isdigit(s[i]))
	            {
	                int val = s[i]-'0';
	                q.push(val);
	                i++;
	            }
	            int power=q.size()-1;
	            do
	            {
	                no=q.front()*(pow(10,power));
	                sum1=sum1+no;
	                q.pop();
	                power--;
	            }while(!q.empty());
	          
	        }
	          
	       i++;
	    }
	    sum=sum+sum1;
	    cout<<sum<<endl;
	}
	return 0;
}



//O(n)
// C++ program to calculate sum of all numbers present 
// in a string containing alphanumeric characters 
#include <iostream> 
using namespace std; 

// Function to calculate sum of all numbers present 
// in a string containing alphanumeric characters 
int findSum(string str) 
{ 
	// A temporary string 
	string temp = ""; 

	// holds sum of all numbers present in the string 
	int sum = 0; 

	// read each character in input string 
	for (char ch: str) 
	{ 
		// if current character is a digit 
		if (isdigit(ch)) 
			temp += ch; 

		// if current character is an alphabet 
		else
		{ 
			// increment sum by number found earlier 
			// (if any) 
			sum += atoi(temp.c_str()); 

			// reset temporary string to empty 
			temp = ""; 
		} 
	} 

	// atoi(temp.c_str()) takes care of trailing 
	// numbers 
	return sum + atoi(temp.c_str()); 
} 

// Driver code 
int main() 
{ 
	// input alphanumeric string 
	string str = "12abc20yz68"; 

	cout << findSum(str); 

	return 0; 
} 
