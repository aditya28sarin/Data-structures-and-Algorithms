#include <iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

int main() {

int cases,number;
int limit=10000;
long long int sum=0;

int *ptr;
ptr=new int[limit];


	scanf("%ld",&cases);

	while(cases--)
	{

	    scanf("\n%ld",&number);

	    int j=number;
	    for (int i=2;i<=limit;i++)
	    {

	        if(i%2==0)
	        {

	            if(j>0)
	            {
	                sum=sum+pow(i,2);
	                j--;
	            }

	        }
	        else
            {

                continue;;
            }

	    }

	    printf("%lld\n",sum);
        sum=0;
	}
	return 0;
}
