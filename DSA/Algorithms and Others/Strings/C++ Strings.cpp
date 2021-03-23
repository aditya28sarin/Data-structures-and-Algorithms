#include<iostream>
#include<cstring>
#include<string.h>

using namespace std;

int main()
{

    char str1[100],str2[100];
    int j=0,cases;

    cin>>cases;

    while(j<cases)
    {

        cin>>str1;

        cin>>str2;

        if(strlen(str1)>strlen(str2))
        {

            cout<<strlen(str1)<<endl;
            strcat(str1,str2);
            cout<<str1<<endl;
        }

        if(strlen(str1)<strlen(str2))
        {

            cout<<strlen(str2)<<endl;
            strcat(str1,str2);
            cout<<str1<<endl;
        }
    j++;
    }

}
