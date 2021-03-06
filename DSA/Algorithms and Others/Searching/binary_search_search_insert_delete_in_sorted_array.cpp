#include<bits/stdc++.h>
using namespace std;

int searchElement(int arr[], int l, int r, int key)
{
    int mid = l+(r-l)/2;

    if(arr[mid]==key)
        return mid;

    if(key<arr[mid])
        return search(arr,l,mid-1,key);
    
    if(key>arr[mid])
        return search(arr,mid+1,r,key);

    return -1;
}

int insertElement(int arr[], int n, int key)
{int i;
    for(i=n-1; (i>=0 && key<arr[i]) ;i++)
    {
        arr[i+1]=arr[i];
    }

    arr[i+1]=key;

    return n+1;
    
}


int deleteElement(int arr[], int n, int key)
{
    int i=0;

    int pos = search(arr,0,n-1,key);
    
    while(pos<n-1)
    {
        arr[pos]=arr[pos+1];
        pos++;
    }

    return n-1;
}


int main()  
{  
    int i;  
    int input_array[] = { 10, 20, 30, 40, 50 };  
  
    int size_of_array = sizeof(arr) / sizeof(arr[0]);  
    int key = 30;  
  
    int search_index=searchElement(input_array,0,size_of_array-1,key);
    cout<<key<<" is at index: "<<search_index<<endl;
  

    cout << "Array before deletion\n";  
    for (i = 0; i < size_of_array; i++)  
        cout << input_array[i] << " ";  
    int key2=30;
    size_of_array = deleteElement(input_array, size_of_array, key2);  
  
    cout << "\n\nArray after deletion\n";  
    for (i = 0; i <size_of_array; i++)  
        cout << input_array[i] << " ";  

        cout<<endl;

    int key3=15;
      size_of_array= insertElement(input_array, size_of_array, key3);  
  
        cout << "\n\nArray after insertion\n";  
    for (i = 0; i <n\size_of_array; i++)  
        cout << input_array[i] << " ";  
}