// URL: https://www.geeksforgeeks.org/bubble-sort/

#include<bits/stdc++.h>
using namespace std;

void iterativeBubbleSort(int input_array[], int size_of_array)
{
    for(int i=0;i<size_of_array-1;i++)
    {   int flag=0;
        for(int j=0;j<size_of_array-i-1;j++)
        {
            if(input_array[j]>input_array[j+1])
            {
                int temp=input_array[j];
                input_array[j]=input_array[j+1];
                input_array[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }   
}

void recursiveBubbleSort(int input_array[], int size_of_array)
{
    if(size_of_array<=1)
        return;
    
    for(int i=0; i<size_of_array-1;i++)
    {
        if(input_array[i]>input_array[i+1])
        {
            int temp =input_array[i];
            input_array[i]=input_array[i+1];
            input_array[i+1]=temp;
        }
    }
	
    recursiveBubbleSort(input_array,size_of_array-1);
}

void printArray(int input_array[], int size_of_array)  
{  
    int i;  
    for (i = 0; i < size_of_array; i++)  
        cout << input_array[i] << " ";  
    cout << endl;  
}  
  
int main()  
{  
    int size_of_array;
    cin>>size_of_array;

    int input_array[size_of_array];

    for(int i=0;i<size_of_array;i++)
    {
        cin>>input_array[i];
    } 

    iterativeBubbleSort(input_array, size_of_array);  
    cout<<"Sorted array: \n";  
    printArray(input_array, size_of_array);  

    recursiveBubbleSort(input_array, size_of_array);  
    cout<<"\n\nSorted array with Recursive Bubble Sort: \n";  
    printArray(input_array, size_of_array);  
    return 0;  
}  
  