#include<iostream>
#include<algorithm>
using namespace std;

///my approach O(n^2)
//void selectionSortFunc(int arr[], int n)
//{
//    int max_index,min_index;
//
//    for(int i=0;i<n-1;i++)
//    {
//        max_index=i;
//        min_index=i;
//        for(int j=i+1;j<n;j++)
//        {
//            if(i%2==0)
//            {
//                if(arr[j]>arr[max_index])
//                {
//                    max_index=j;
//                }
//            }
//            else
//            {
//                if(arr[j]<arr[min_index])
//                {
//                    min_index=j;
//                }
//            }
//        }
//        if(i%2==0)
//        {
//            int temp=arr[i];
//            arr[i]=arr[max_index];
//            arr[max_index]=temp;
//        }
//        else
//        {
//            int temp=arr[i];
//            arr[i]=arr[min_index];
//            arr[min_index]=temp;
//        }
//    }
//}


///efficient algorithm O(nlogn)
void alternateSort(int arr[], int n)
{
    sort(arr,arr+n);

    int i=0,j=n-1;
    while(i<j)
    {
        cout<<arr[j--]<<" ";
        cout<<arr[i++]<<" ";
    }
    if(n%2!=0)
    {
        cout<<arr[i];
    }
}

//main function common to both algorithms
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
        alternateSort(arr,n);

        //selectionSortFunc(arr,n);
//        for(int i=0;i<n;i++)
//        {
//            cout<<arr[i]<<" ";
//        }
    }
}
