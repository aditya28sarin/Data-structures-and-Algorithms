#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;


int binarySearch(int arr[], int l, int r, int key)
{

    while(r>=l)
    {
        int m=l+(r-l)/2;

        if(key==arr[m])
            return m;
        if(key>arr[m])
            l=m+1;
        else
            r=m-1;
    }
    return -1;
}


void printUnion(int arr1[], int arr2[], int m, int n)
{

    if (m < n)
  {
    int p=0;
    sort(arr1, arr1 + m);
     for (int i=0; i<m; i++)
        {
            if(arr2[i]!=arr2[i+1])
                p++;
        }
    int cp=0;
    for (int i=0; i<n; i++)
        if (binarySearch(arr1, 0, m-1, arr2[i]) == -1)
            //cout << arr2[i] << " ";
            cp++;
    cout<<cp+p<<endl;
  }
  else{
    {
    int p=0;
    sort(arr2, arr2 + n);
     for (int i=0; i<n; i++)
        {
            if(arr1[i]!=arr1[i+1])
                p++;
        }
    int cp=0;
    for (int i=0; i<m; i++)
        if (binarySearch(arr2, 0, n-1, arr1[i]) == -1)
            //cout << arr2[i] << " ";
            cp++;
    cout<<cp+p<<endl;
  }
  }
}

int main()
{
    int cases;
    cin>>cases;

    while(cases--)
    {
        int n1,n2;
        cin>>n1>>n2;
        int p1=0,p2=0;
     int arr1[n1],arr2[n2];

        for(int i=0;i<n1;i++)
        {
            cin>>arr1[i];
        }

        for(int i=0;i<n2;i++)
        {
            cin>>arr2[i];
        }

       printUnion(arr1,arr2,n1,n2);

    }
}


