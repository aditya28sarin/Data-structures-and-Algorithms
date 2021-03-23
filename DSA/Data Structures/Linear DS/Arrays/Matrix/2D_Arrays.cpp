#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    int test_cases, size_of_array,temp;

    int *arr=(int *)malloc(size_of_array * size_of_array * sizeof(int *));
    cin>>test_cases;

    int a=0,i,j;

    while(a<test_cases)
    {

        cin>>size_of_array;

        for(i=0;i<size_of_array;i++)
        {

            for(j=0;j<size_of_array;j++)
            {

                cin>> *(arr+i*size_of_array+j);
            }
        }

        for(i=0;i<size_of_array;i++)
        {

            for(j=0;j<size_of_array;j++)
            {

                cout<< *(arr+j*size_of_array+i)<<" ";
            }
        }
cout<<endl;
        a++;

    }
}
