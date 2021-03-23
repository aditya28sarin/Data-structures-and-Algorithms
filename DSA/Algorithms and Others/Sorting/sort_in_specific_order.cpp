#include<bits/stdc++.h>
using namespace std;

/// My Method --> Takes more time than expected

void swapfunc(int &x,int &y)
{

   int temp;
   temp=x;
   x=y;
   y=temp;
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
       vector <int> arr1,arr2;
       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
       }


       for(int i=0;i<n;i++)
       {
           if(arr[i]%2!=0)
           {

               arr1.push_back(arr[i]);

           }
           else
           {
               arr2.push_back(arr[i]);
           }

       }

   arr1.insert(arr1.end(),arr2.begin(),arr2.end());



       for(int i=0;i<n;i++)
       {
           for(int j=i;j<n;j++)
           {
           if(arr1[i]%2!=0)
           {
               if(arr1[j]>=arr1[i])
               {

                   swapfunc(arr1[j],arr1[i]);
               }
           }
           if(arr1[i]%2==0)
           {
               if(arr1[j]<=arr1[i])
               {

                   swapfunc(arr1[j],arr1[i]);
               }
           }
       }
       cout<<arr1[i]<<" ";

   }
   }
}

///-------------------------------------------------------------------------
/// Using Negative multiplication

// To do two way sort. First sort even numbers in
// ascending order, then odd numbers in descending
// order


void twoWaySort(int arr[],int n)
{
//make all odd numbers negative
   for (int i=0;i<n;i++)
   {
       if(arr[i]%2!=0)
       {
           arr[i]*=-1;
       }
   }

//sort all numbers
sort(arr,arr+n);

//regaining original array
for (int i=0;i<n;i++)
{
   if(arr[i]%2!=0)
   {
       arr[i]*=-1;
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
       int arr[n];
       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
       }
       twoWaySort(arr,n);
       for(int i=0;i<n;i++)
       {
           cout<<arr[i]<<" ";
       }

cout<<endl;
}
}


///---------------------------------
/// Using Partition
void twoWaySort(int arr[], int n)
{
   //current indexes from left to right

   int l=0;int r=n-1;

   //count of odd numbers
   int k =0;

   while(l<r)
   {
       //find first odd number from left side
       while(arr[l]%2!=0)
       {
           l++;
           k++;
       }


   //find first even number from right side
   while(arr[r]%2==0 && l<r)
   {
       r--;
   }

       if(l<r)
       swap(arr[l],arr[r]);
   }
   sort(arr,arr+k,greater<int>());
   sort(arr+k,arr+n);
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
       twoWaySort(arr,n);
       for(int i=0;i<n;i++)
       {
           cout<<arr[i]<<" ";
       }

cout<<endl;
}
}

///using own comparator

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

//When both the elements are even: In this case, the smaller element must appear in the left of the larger element in the sorted array.
//When both the elements are odd: The larger element must appear on left of the smaller element.
//One is odd and the other is even: The element which is odd must appear on the left of the even element.

// To do two way sort. Make comparator function
// for the inbuilt sort function of c++ such that
// odd numbers are placed before even in descending
// and ascending order respectively

bool compare(int a, int b)
{
// If both numbers are even, smaller number should
    // be placed at lower index

  if(a%2==0 && b%2==0)
  {
    return a<b;
  }
  if(a%2!=0 && b%2!=0)
  {
    return b<a;
  }

  if(a%2!=0)
    return true;
  return false;
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
        sort(arr,arr+n,compare);
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }

cout<<endl;
}
}
