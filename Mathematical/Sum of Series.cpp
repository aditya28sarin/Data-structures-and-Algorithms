#include <iostream>
using namespace std;

int main() {


	int cases,terms;

	cin>>cases;

	while(cases--)
    {
        cin>>terms;

        int sum=0;

        for (int i=1;i<=terms;i++)
        {

            sum=sum+i;
        }

        cout<<sum<<endl;
    }



	return 0;
}
