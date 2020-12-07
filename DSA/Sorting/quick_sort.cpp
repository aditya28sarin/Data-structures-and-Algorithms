// URL: https://www.geeksforgeeks.org/quick-sort/

#include <bits/stdc++.h> 
using namespace std;  


int partitionArray(int input_array[], int left_ptr, int right_ptr)
{
    int pivot_element = input_array[right_ptr];
    int i = left_ptr-1;
    int j =left_ptr;
    while(j<right_ptr)
    {
        if(input_array[j]<pivot_element)
        {
            i++;
            swap(input_array[i],input_array[j]);
        }
        j++;
    }
    swap(input_array[i+1], input_array[right_ptr]);
    return (i+1);
}


void quickSort(int input_array[], int left_ptr, int right_ptr)
{
    if(left_ptr<right_ptr)
    {
        int pivot_index=partitionArray(input_array,left_ptr,right_ptr);

        quickSort(input_array, left_ptr, pivot_index-1);
        quickSort(input_array, pivot_index+1, right_ptr);
    }
}



void printArray(int input_array[], int array_size)  
{  
    int i;  
    for (i = 0; i < array_size; i++)  
        cout << input_array[i] << " ";  
    cout << endl;  
}  
  
int main()  
{  
    int array_size;
    cin>>array_size;

    int input_array[array_size];  
    for(int i=0;i<array_size;i++)
    {
        cin>>input_array[i];
    }  

    quickSort(input_array, 0, array_size - 1);  
    cout <<"Sorted array: \n";  
    printArray(input_array, array_size);  
    return 0;  
}  