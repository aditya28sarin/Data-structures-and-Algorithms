#include<iostream>
#include<typeinfo>
using namespace std;

int main()
{
    int cases,j=0;
    string str;

    int count1=0;

    cin>>cases;

    while(j<cases)
    {
        cin>>str;
        if(str.length()==1)
        {
        if(int(str[0])>=48 && int(str[0])<=57)
        {

        cout<<sizeof(int)<<endl;
        }
        else
        {

            cout<<sizeof(char)<<endl;
        }
        }

else{


    for(int i=0;i<str.length();i++)
    {
        static int flag=0;

          if(flag==1)
        {
            count1++;
        }
         if(str[i]=='.')
        {
            flag=1;
        }

    }
        if( count1<=7)
        {

                cout<<sizeof(float)<<endl;
        }
        if(count1>7)
        {

            cout<<sizeof(double)<<endl;
        }


}
count1=0;
j++;
}


}
