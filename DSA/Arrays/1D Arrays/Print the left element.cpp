#include<iostream>

using namespace std;

int main()
{

    int cases;

    cin>>cases;

    while(cases--)
    {

        int size1;
        cin>>size1;

        int arr[size1];
        int value1,value_1,value2,value_2;
        for(int i=1;i<=size1;i++)
        {
            cin>>arr[i];
        }

        for(int i=1;i<=size1;i++)
        {
            if(i%2!=0)
            {        value1 = arr[0];
                for(int j=1;j<=size1;j++)
                {

                    if(arr[j]>=value1)
                    {


                        value1=arr[j];
                        value_1=j;

                    }
                }

                for(int k=value_1;k<size1;k++)
                {
                arr[k]=arr[k+1];

                }

            }
            else
            {   value2 = arr[0];
               for(int j=1;j<=size1;j++)
                {

                    if(arr[j]<=value2)
                    {
                        value2=arr[j];
                        value_2=j;


                    }
                }
                 for(int k=value_2;k<size1;k++)
                {
                arr[k]=arr[k+1];

                }
                //arr[value_2]=arr[value_2-1];

            }
        }

        cout<<endl<<endl;
        for(int i=1;i<=size1;i++)
        {

            cout<<arr[i];
        }
    }
}
