#include<bits/stdc++.h>
using namespace std;

int binarySearch(int lower, int upper, int power_of_soldiers[], int power_of_bhisu)
{
	if(upper>=lower)
	{
		int mid = lower +(upper-lower)/2;

		if(power_of_soldiers[mid]==power_of_bhisu)
			return mid;
	

		if(power_of_soldiers[mid]>power_of_bhisu)
		
			return binarySearch(lower,mid-1,power_of_soldiers,power_of_bhisu);
		
		
		return binarySearch(mid+1,upper,power_of_soldiers,power_of_bhisu);
	}
	return -1;

}

int main()
{
	int no_of_soldiers,  no_of_rounds, power_of_bhisu;

    cin>>no_of_soldiers;

	int power_of_soldiers[no_of_soldiers];

	for(int i=0;i<no_of_soldiers;i++)
	{
		cin>>power_of_soldiers[i];
	}

	cin>>no_of_rounds;

	while(no_of_rounds--)
	{
		cin>>power_of_bhisu;

		int index = binarySearch(0,no_of_soldiers-1,power_of_soldiers,power_of_bhisu);
        int count;
        if(index==-1)
        {
            index = no_of_soldiers;
            count=index;
        }
        else
        {
             count = index+1;
        }
		int product_defeat=0;
		for(int i=0;i<count;i++)
		{
			product_defeat=product_defeat+power_of_soldiers[i];
		}

		cout<<count<<" "<<product_defeat<<endl;
	}
}