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

        char arr[size1];
        string str1;

        for(int i=0;i<size1;i++)
        {

            cin>>arr[i];
        }

        for(int i=0;i<size1;i++)
        {

            str1.push_back(arr[i]);
        }

        cout<<str1<<endl;



    }
}
