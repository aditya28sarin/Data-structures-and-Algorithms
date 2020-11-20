#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{

    int  no_of_cases,n;
    int* value = (int *)malloc(no_of_cases * sizeof(int));

    cin>>no_of_cases;

    int i=0;

    while(i<no_of_cases)
    {

    cin>>n;

    if(n<5)
    {
        value[i]=-1;

    }
    else if (n==5)
    {
        value[i]=0;


    }

    else{
        value[i]=1;

    }
        i++;
    }

    for(int j=0;j<no_of_cases;j++)
    {

        if(value[j]==-1)
        {
         cout<<"Less than 5"<<endl;
        }
        else if(value[j]==0)
        {

               cout<<"Equal to 5"<<endl;
        }
        else if(value[j]==1)
        {

        cout<<"Greater than 5"<<endl;
        }
    }
}
