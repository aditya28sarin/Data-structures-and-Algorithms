#include<iostream>
using namespace std;

//Method 1
int main()
{

   int cases;

   cin>>cases;

   while(cases--)
   {
       int n,d;
       cin>>n>>d;
       int arr[n],temp[d];
       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
           if(i<d)
           {

           temp[i]=arr[i];

           }
       }


       for(int i=0;i<n-d;i++)
       {

           arr[i]=arr[i+d];

           cout<<arr[i]<<" ";
       }

       for(int i=0;i<d;i++)
       {

           cout<<temp[i]<<" ";
       }



   }
}




//Method 2

#include<iostream>
using namespace std;

int main()
{
   int cases;

   cin>>cases;

   while(cases--)
   {
       int size1,rotate_size;

       cin>>size1>>rotate_size;
       int arr[size1],arr1[size1];

       for(int i=0;i<size1;i++)
       {
           cin>>arr[i];
       }

        for(int i=0;i<size1;i++)
       {
           if(rotate_size==size1)
           {
           rotate_size=0;
           }
           arr1[i]=arr[rotate_size];
           rotate_size++;
           cout<<arr1[i]<<" ";

           }

       cout<<endl;




   }

}

//method 3
int main()
{

    int cases;

    cin>>cases;

    while(cases--)
    {
        int n,d;
        cin>>n>>d;
        int arr[n],temp;
        auto j=0;

        for(int i=0;i<n;i++)
        {

            cin>>arr[i];
        }

        for(int i=0;i<d;i++)
        {
            temp=arr[0];
            for(j=0;j<n-1;j++)
            {
                arr[j]=arr[j+1];
            }
            arr[j]=temp;
        }

        for(int i=0;i<n;i++)
        {

            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}
