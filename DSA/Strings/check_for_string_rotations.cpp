// URL: https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/

#include<bits/stdc++.h>
using namespace std;


bool checkIfStringRotated(string str1, string str2)
{
	string temp =str1 + str1;
	int size2= str2.size();
	int count=0;
	int i=0;
	bool flag=true;
	while(i<temp.length())
	{
		if(str2[0]!=temp[i])
		{
			i++;
		}
		else{
			int j = 0;
			while(j<str2.length())
			{
				if(temp[i]!=str2[j])
					flag=false;
				i++;
				j++;
			}
			break;
		}
	}
	return flag;
}

int main()
{
	string str1,str2;

	cout<<"Enter String 1: ";
	cin>>str1;
	
	cout<<"Enter String 2: ";
	cin>>str2;

	bool flag = checkIfStringRotated(str1,str2);
	
	if(flag==true)
	{
	    cout<<"String 2 is a rotated version of 1"<<endl;
	}
	else{
	    
	    cout<<"String 2 is not a rotated version of 1";
	}
}