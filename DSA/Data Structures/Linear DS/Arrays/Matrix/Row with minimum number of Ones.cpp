#include<iostream>
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int r,c;
        cin>>r>>c;
        int arr[r][c];
        int arr1[r]={0};

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>arr[i][j];
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(arr[i][j]==1)
                {

                    arr1[i]=arr1[i]+1;
                }
            }
        }
            int temp=500;
            int k=1,cp=0;
        for(int i=0;i<r;i++)
        {
            if(arr1[i]!=0)
            {
            if(arr1[i]<=temp)
            {
             temp=arr1[i];
             for(int j=0;j<=i;j++)
             {
                if(arr1[i]==arr1[j])
                {
                     k=j;
                     break;
                }
                else
                {
                    k=i;
                }
             }
            }
            }
            if(arr1[i]==0)
            {
                cp++;
            }
        }
if(cp==r)
{
    k=-1;
}
        cout<<k<<endl;
    }
}
