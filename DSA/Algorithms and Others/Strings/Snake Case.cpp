#include<iostream>
#include<algorithm>

using namespace std;

int main()
{

    int cases;
    cin>>cases;
    while(cases--)
    {
        int size1;
        cin>>size1;
        string str;
        cin.ignore();
        getline(cin,str);

       str[0]=tolower(str[0]);
        for(int i=0;i<=size1;i++)
        {

            if(str[0]==' ')
            {
                str.erase(remove(str.begin(),str.end(),str[0]),str.end());
                str[1]=tolower(str[1]);
            }
         if(str[i]==' ')
            {
                str[i]='_';
            }


            str[i]=tolower(str[i]);
        }

        cout<<str<<endl;



    }
}
