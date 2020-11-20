#include <iostream>
using namespace std;

int main() {
	
    int cases;
    cin>>cases;

    while(cases--)
    {
        int n1,n2;
        cin>>n1>>n2;

        cout<<(n1+n2)%12<<endl;
    }

	return 0;
}