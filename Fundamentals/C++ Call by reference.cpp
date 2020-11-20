#include<iostream>
using namespace std;
#include<string>

void reverse_dig(int &a,int &b);
void swap(int &a,int &b);
int main()
{

    int t;
    cin>>t;
    while (t--)
    {
        int a,b;
        cin>>a>>b;

        reverse_dig(a,b);
        swap(a,b);

        cout<<a<<" "<<b<<endl;
    }
    return 0;
    }


void reverse_dig(int &a,int &b)
{

string str=to_string(a);
string str1=to_string(b);

string str_a=str;
string str_a_1=str1;

int j=str.length()-1;
for(int i=0;i<str.length();i++)
{

    str[i]=str_a[j];
    j--;

}

int k=str1.length()-1;
for(int i=0;i<str1.length();i++)
 {
    str1[i]=str_a_1[k];
    k--;

}
a=stoi(str);
b=stoi(str1);

}
void swap(int &a,int &b)
{
    int temp;

    temp=a;
    a=b;
    b=temp;
}


