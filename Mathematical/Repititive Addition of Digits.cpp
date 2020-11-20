#include <bits/stdc++.h>
using namespace std;

int main() {

    int cases;
    cin>>cases;
    
    while(cases--)
    {
        int num,x;
        cin>>num;
        int sum=0;
        while(true)
        {
            if(num==0 && sum<10)
            {
                break;
            }
            
            if(num>0)
            {
                x=num%10;
                num=num/10;
                sum=sum+x;
            }
            else
            {
                num=sum;
                sum=0;
            }
        }
        cout<<sum<<endl;
    }
    
    
    
	return 0;
}