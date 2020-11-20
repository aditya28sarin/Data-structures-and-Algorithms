#include<iostream>
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int x,y;
        cin>>x>>y;
        int arr[x][y];
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                cin>>arr[i][j];
            }
        }
        int val,maxVal=0,index;
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(arr[i][j]==1)
                {
                    val++;
                   // ones[i]=ones[i]+1;
                }
                if(val>maxVal)
                {
                    maxVal=val;
                    index=i;
                }
            }
        }

        cout<<index<<endl;



    }
}
