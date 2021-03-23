#include<iostream>


using namespace std;

int main()
{

    int cases;

    cin>>cases;

    while(cases--)
    {

        string str,alpha,num,special;

        cin>>str;

        for(int i=0;i<str.length();i++)
        {
            if(str[i]>='a' && str[i]<='z'  || str[i]>='A' && str[i]<='Z' )
            {
                    alpha.push_back(str[i]);
            }
            if(isdigit(str[i]))
            {
                num.push_back(str[i]);
            }
            if(iscntrl(str[i]) || ispunct(str[i]))
            {
                special.push_back(str[i]);
            }

        }



        cout<<alpha<<endl;

        cout<<num<<endl;

        cout<<special<<endl;
    }
}
