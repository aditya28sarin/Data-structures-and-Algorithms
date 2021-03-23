#include<iostream>
using namespace std;

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
        int n1,n2;
        cin>>n1;
        int arr1[n1];
        for(int i=0;i<n1;i++)
        {
            cin>>arr1[i];
        }

        cin>>n2;
        int arr2[n2];
        for(int i=0;i<n2;i++)
        {
            cin>>arr2[i];
        }

        mergeSort(arr1,0,n1-1);
        mergeSort(arr2,0,n2-1);

        cout<<arr1[n1-1]*arr2[0]<<endl;

    }
}
