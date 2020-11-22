#include<bits/stdc++.h>
using namespace std;

void binarySearch(int lower, int upper, int power_of_soldiers[], int power_of_bhisu, int &soldier_power_less_bhisu)
{
	if(upper>=lower)
	{
		int mid = lower +(upper-lower)/2;

		if(power_of_soldiers[mid]==power_of_bhisu)
		{
		    soldier_power_less_bhisu=mid+1;
			    binarySearch(mid+1,upper,power_of_soldiers,power_of_bhisu, soldier_power_less_bhisu);
   
		}

		if(power_of_soldiers[mid]>power_of_bhisu)
		     binarySearch(lower,mid-1,power_of_soldiers,power_of_bhisu, soldier_power_less_bhisu);
		
		
		binarySearch(mid+1,upper,power_of_soldiers,power_of_bhisu,soldier_power_less_bhisu);
	}

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

        int soldier_power_less_bhisu;
        
        if(power_of_bhisu>power_of_soldiers[no_of_soldiers-1])
        {
            soldier_power_less_bhisu = no_of_soldiers;
        }
        else if(power_of_bhisu<power_of_soldiers[0])
        {
            cout<<"0 0";
            continue;
        }
        else
        {
    	    binarySearch(0,no_of_soldiers-1,power_of_soldiers,power_of_bhisu, soldier_power_less_bhisu);
        }
        
		int sum_of_defeat=0;
		for(int i=0;i<soldier_power_less_bhisu;i++)
		{
			sum_of_defeat=sum_of_defeat+power_of_soldiers[i];
		}

		cout<<soldier_power_less_bhisu<<" "<<sum_of_defeat<<endl;
	}
}