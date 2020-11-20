#include<iostream>
using namespace std;
void sorting_array(int arr[], int n)
{
    for (int i=0;i<n;i++)
    {
        int temp=arr[i];
        for(int j=i;j<n;j++)
        {
        if(arr[j]<=temp)
        {
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
        }
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
        int arr[n],cp=0;

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sorting_array(arr,n);
 int t=0;
 while(arr[t]==arr[0])
 {
    t++;
 }

 if(t==n){
    cout<<-1;
 }
 else{
    cout<<arr[0]<<" "<<arr[t]<<endl;
 }
}
}
