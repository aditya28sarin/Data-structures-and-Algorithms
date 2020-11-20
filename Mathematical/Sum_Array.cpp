#include<iostream>
using namespace std;

int main() {
	int n, no_of_elem_array;
	int arr[50], sum[50]={0};

        cin>>n;

	int j=0;

	while(j<n)
	{
	    cin>>no_of_elem_array;

	    for( int i=0;i<no_of_elem_array;i++)
	    {
	        cin>>arr[i];
	     }


	    for( int i=0;i<no_of_elem_array;i++)
	    {
	       sum[j]=sum[j]+arr[i];
	    }
            j++;
	}
for(int i=0; i<n; i++){
    cout<<sum[i]<<"\n";
}


	return 0;
}
