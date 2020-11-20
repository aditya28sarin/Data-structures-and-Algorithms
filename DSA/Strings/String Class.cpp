#include<iostream>

using namespace std;

int main()
{

    string str1 ("First String");
    cout<<str1<<endl;

    string str2(str1);
    cout<<str2<<endl;

    string str3(5,'#');

    cout<<str3<<endl;

    string str4(str1,6,6);
    cout<<str4<<endl;

    string str5(str2.begin(),str2.begin() +5 );
    cout<<str5<<endl;

    string str6 =str5;
    cout<<str6<<endl;

    //str6.clear();
    //cout<<str6<<endl;

    int len=str6.length(); //same as str6.size();
    cout<<len<<endl;

    char ch=str6.at(2);
    cout<<'\n';
    cout<<ch;

}
