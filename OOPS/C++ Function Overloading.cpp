#include <iostream>
using namespace std;

void max(int x,int y)
{
if(x>y)
{

    cout<<x<<endl;
}
else
{
    cout<<y<<endl;

}
}

void max(char x,char y)
{
if(x>y)
{

    cout<<x<<endl;
}
else
{
    cout<<y<<endl;

}
}



void max(float x,float y)
{
if(x>y)
{

    cout<<x<<endl;
}
else
{
    cout<<y<<endl;

}

}



int main() {

int cases;

cin>>cases;
while(cases--)
	int n;
	int x,y;
	char a,b;
	float f1,f2;

	cin>>n;

	switch(n)
	{
    case 1:

        cin>>x>>y;

        max(x,y);
        break;

    case 2:

        cin>>a>>b;

        max(a,b);
        break;

    case 3:

        cin>>f1>>f2;

        max(f1,f2);
        break;

	}
}






	return 0;
}
