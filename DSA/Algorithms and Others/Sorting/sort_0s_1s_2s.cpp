//URL: https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

#include<iostream>
using namespace std;

// Uisng a sorting algorithm in O(nlogn)
void mergeArray(int arr[], int l, int m, int r)
{
    int i,j,k;
    int n1= m-l+1;
    int n2= r-m;

    int L[n1],R[n2];

    for(i=0;i<n1;i++)
    {
        L[i]=arr[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=arr[m+1+j];
    }

    i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
       else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }

       while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }


}


void mergeSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int m =l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        mergeArray(arr,l,m,r);
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
        int arr[n];

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        mergeSort(arr,0,n-1);

        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}



//dutch national flag algo
void sort012(int arr[], int n)
{
    int low=0;
    int mid=0;
    int high=n-1;

    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            int temp=arr[mid];
            arr[mid]=arr[low];
            arr[low]=temp;

            mid++;
            low++;
        }
       else if(arr[mid]==1)
        {
            mid++;
        }
        else if(arr[mid]==2)
        {
            int temp=arr[mid];
            arr[mid]=arr[high];
            arr[high]=temp;
            high--;
        }
    }
}




void printArray(int arr[], int arr_size) 
{ 
    for (int i = 0; i < arr_size; i++) 
        cout << arr[i] << " "; 
} 
  

int main() 
{ 
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    sort012(arr, n); 
  
    cout << "array after segregation "; 
  
    printArray(arr, n); 
  
    return 0; 
} 