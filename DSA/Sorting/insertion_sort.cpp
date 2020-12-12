URL: https://www.geeksforgeeks.org/insertion-sort/

#include<iostream>
using namespace std;

void insertionSort(int input_array[],int n)
{
    for (int i=1;i<n;i++)
    {
        int key=input_array[i];
        int j=i-1;

        while(j>=0 && input_array[j]>key)
        {
            input_array[j+1]=input_array[j];
            j--;
        }
        input_array[j+1]=key;
    }
}

int main()
{
    int cases;
    cin>>cases;

    while(cases--)
    {
        int n;
        cin>>n;
        int input_array[n];

        for(int i=0;i<n;i++)
        {
            cin>>input_array[i];
        }

        insertionSort(input_array,n);
        for(int i=0;i<n;i++)
        {
            cout<<input_array[i]<<" ";
        }
    }
}


//recursive

#include<iostream>
using namespace std;
void insertionSortRecursive(int input_array[],int n)
{

    if(n<=1)
        return;

        insertionSortRecursive(input_array,n-1);

        int key=input_array[n-1];
        int j=n-2;

        while(j>=0 && input_array[j]>key)
        {
            input_array[j+1]=input_array[j];
            j--;
        }
        input_array[j+1]=key;
}

void printArray(int input_array[], int n)
{
    for (int i=0; i < n; i++)
        cout << input_array[i] <<" ";
}

/* Driver program to test insertion sort */
int main()
{
    int input_array[] = {12, 11, 13, 5, 6};
    int n = sizeof(input_array)/sizeof(input_array[0]);

    insertionSortRecursive(input_array, n);
    printArray(input_array, n);

    return 0;
}
 
