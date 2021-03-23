// Bishu went to fight for Coding Club. There were N soldiers with various powers.
 // There will be Q rounds to fight and in each round Bishu's power will be varied.
 // With power M, Bishu can kill all the soldiers whose power is less than or equal to M(<=M). 
 // After each round, All the soldiers who are dead in previous round will reborn.Such that in 
 // each round there will be N soldiers to fight. As Bishu is weak in mathematics, help him to
 // count the number of soldiers that he can kill in each round and total sum of their powers.

// 1<=N<=10000

// 1<=power of each soldier<=100

// 1<=Q<=10000

// 1<=power of bishu<=100

-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

// Returns soldiers with less power than bishu using binary search. 
void binarySearch(int lower, int upper, int power_of_soldiers[], int power_of_bhisu, int &soldier_power_less_bhisu)
{
	if(upper>=lower)
	{
		int mid = lower +(upper-lower)/2;

		if(power_of_soldiers[mid]==power_of_bhisu)
		{
		    soldier_power_less_bhisu=mid+1;
			    BinarySearch(mid+1,upper,power_of_soldiers,power_of_bhisu, soldier_power_less_bhisu);
   
		}

		if(power_of_soldiers[mid]>power_of_bhisu)
		     BinarySearch(lower,mid-1,power_of_soldiers,power_of_bhisu, soldier_power_less_bhisu);
		
		
		BinarySearch(mid+1,upper,power_of_soldiers,power_of_bhisu,soldier_power_less_bhisu);
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