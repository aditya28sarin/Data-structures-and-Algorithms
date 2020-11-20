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

        for (int i=0;i<str.length();i++)
        {

            if(isupper(str[0]))

            {
                str[i]=toupper(str[i]);
            }

            if(islower(str[0]))

            {
                str[i]=tolower(str[i]);
            }
        }
        cout<<str<<endl;
    }

}
