#include<iostream>
using namespace std;

//void sorting_array(int arr[], int n)
//{
//
//    for (int i=1;i<=n-1;i++)
//    {
//        int temp=arr[i];
//        for(int j=i;j<n;j++)
//        {
//        if(arr[j]<=temp)
//        {
//            temp=arr[j];
//            arr[j]=arr[i];
//            arr[i]=temp;
//        }
//        }
//    }
//}
//int main()
//{
//    int cases;
//    cin>>cases;
//
//    while(cases--)
//    {
//
//        int n;
//        cin>>n;
//        int arr[n],i;
//
//        for(i=1;i<=n-1;i++)
//        {
//            cin>>arr[i];
//        }
//        sorting_array(arr,n);
//            int j;
//        for(j=1;j<=n-1;j++)
//        {
//            if(arr[j]!=j)
//            {
//                break;
//            }
//        }
//       cout<<j<<endl;
//
//
//
//    }
//}


int main()
{
    int cases;
    cin>>cases;

    while(cases--)
    {

        int n;
        cin>>n;
        int arr[n],i;

        for(i=0;i<n-1;i++)
        {
            cin>>arr[i];
        }
        int res=n*(n+1)/2;

        for(int i=0;i<n-1;i++)
        {
            res=res-arr[i];
        }

        cout<<res<<endl;
    }
}
