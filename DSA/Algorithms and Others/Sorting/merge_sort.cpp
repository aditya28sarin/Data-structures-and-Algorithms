#include<bits/stdc++.h>
using namespace std;


void merge(int input_array[], int left_ptr,int mid_ptr, int right_ptr)
{
    //we create 2 temp arrays to and then merge it back into the input array
    int temp_array1_size=mid_ptr-left_ptr+1;
    int temp_array2_size=right_ptr-mid_ptr;

    int temp_array_1[temp_array1_size];
    int temp_array_2[temp_array2_size];

    for(int i=0;i<temp_array1_size;i++)
    {
        temp_array_1[i]=input_array[left_ptr+i];
    }

    for(int i=0;i<temp_array2_size;i++)
    {
        temp_array_2[i]=input_array[mid_ptr+1+i];
    }


    // traverse the both temp arrays and compare each element, substitute the smaller
    // of the two inside the input array 
    int temp_array1_index=0,temp_array2_index=0,input_array_index=left_ptr;

    while(temp_array1_index<temp_array1_size && temp_array2_index<temp_array2_size)
    {
        if(temp_array_1[temp_array1_index]< temp_array_2[temp_array2_index])
        {
            input_array[input_array_index]=temp_array_1[temp_array1_index];
            input_array_index++;
            temp_array1_index++;
        }
        else
        {
            input_array[input_array_index]=temp_array_2[temp_array2_index];
            input_array_index++;
            temp_array2_index++;
        }
          
    }

    // if one of the the pointers has not reached the end of one of the two temp
    //arrays then we make sure that it reaches the end and copy the remaining items 
    //inside the input array 
    while(temp_array1_index<temp_array1_size)
    {
        input_array[input_array_index]=temp_array_1[temp_array1_index];   
        temp_array1_index++;
        input_array_index++;
    }

    while(temp_array2_index<temp_array2_size)
    {
        input_array[input_array_index]=temp_array_2[temp_array2_index];
        temp_array2_index++;
        input_array_index++;
    }

}


void mergeSort(int input_array[], int left_ptr, int right_ptr)
{
    if(left_ptr<right_ptr){

    int mid_ptr=(left_ptr+right_ptr)/2;

    mergeSort(input_array,left_ptr,mid_ptr);
    mergeSort(input_array,mid_ptr+1,right_ptr);
    
    merge(input_array,left_ptr,mid_ptr,right_ptr);
    }
       
}

void printArray(int input_array[], int array_size)
{
    for(int i=0;i<array_size;i++)
    {
        cout<<input_array[i]<<" ";
    }
    cout<<endl;
}

/* Driver program to test above functions */
int main() 
{ 
    int array_size;
    cin>>array_size;

    int input_array[array_size];

    for(int i=0;i<array_size;i++)
    {
        cin>>input_array[i];
    }
  
    printf("Given array is \n"); 
    printArray(input_array, array_size); 
  
    mergeSort(input_array, 0, array_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(input_array, array_size); 
    return 0; 
} 