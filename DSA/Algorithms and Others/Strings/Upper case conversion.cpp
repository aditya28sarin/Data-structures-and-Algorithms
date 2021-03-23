#include<iostream>
using namespace std;

int main()
{
    int cases;

    cin>>cases;
        cin.ignore();

    while(cases--)
    {
     string str;



     getline(cin,str);

     for(int i=0;i<str.length();i++)
     {
         if(str[i-1]==' ')
         {
            str[0]=toupper(str[0]);
            str[i]=toupper(str[i]);
         }

     }
        cout<<str<<endl;
    }

}
