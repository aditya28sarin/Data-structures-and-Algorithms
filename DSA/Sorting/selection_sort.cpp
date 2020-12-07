// URL:https://www.geeksforgeeks.org/selection-sort/

#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b)
{
    int temp;
    temp=a;a=b;
    b=temp;
}

void selectionSort(int input_array[], int size_of_array)
{
    for(int i=0;i<size_of_array-1;i++)
    {
       
        for(int j=i+1;j<size_of_array;j++)
        {
            if(input_array[j]<=input_array[i])
            {
                swap(input_array[i],input_array[j]);
            }
        }
    }
     for (int i=0; i < size_of_array; i++)  
        cout << input_array[i] << " ";  
    cout << endl;  
}

//recursive solution
void recursiveSelectionSort(int input_array[], int size_of_array, int start)
{
    if(start==size_of_array-1)
        return;

    int temp = input_array[start];
    int min_index;
    for(int i=start;i<size_of_array;i++)
    {
        if(input_array[i]<=temp)
        {
            temp=input_array[i];
            min_index=i;
        }
    }
    swap(input_array[start],input_array[min_index]);

    recursiveSelectionSort(input_array,size_of_array,start+1);
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
    
    cout << "Sorted array: \n";  
    selectionSort(input_array, size_of_array);  


    cout << "\n\nSorted array with Recursive Solution: \n";  
    recursiveSelectionSort(input_array,size_of_array,0);

    return 0;  
}  