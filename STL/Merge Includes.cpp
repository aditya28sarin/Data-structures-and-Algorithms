#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int main()
{

    set <int> s1={1,2,3,4,5};

    set<int> s2={3,4,5,6,7};

    set<int> s3;

    merge(s1.begin(),s1.end(),s2.begin(),s2.end(),s3.begin());

        set <int> :: iterator st1;
    for(st1=s3.begin();st1!=s3.end();st1++)

    {
        cout<<*st1<<" ";
    }


}
