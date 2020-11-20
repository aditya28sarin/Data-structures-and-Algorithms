#include<isotream>

using namespace std;

int main()
{

    int cases,size1;


    cin>>cases;

    while(cases--)
    {

        cin>>size1;
        int arr[size1],prod=1;

        for(int i=0;i<size1;i++)
        {
            cin>>arr[i];
            prod=prod*arr[i];

        }

        cout<<prod<<endl;


    }

}
