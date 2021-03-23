#include<iostream>

using namespace std;

int main()
{

    int cases;

    cin>>cases;

    while(cases--)
    {

       string str;

       cin>>str;

       int count1=1;


      for(int i=0;i<str.length();i++)
      {

        if(str[i]==str[i+1])
        {

            count1++;
        }
      }



      if(count1==str.length())
      {

          cout<<"YES"<<endl;
      }
      else
      {

          cout<<"NO"<<endl;
      }

    }
}
