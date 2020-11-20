using namespace std;


int main() {
	int cases;
	cin>>cases;
	while(cases--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    int flag=0,index=0;
	    for(int j=0;j<n;j++)
	    {
	        if(arr[j]==1)
	        {
	           flag=1;
	           index=j;
	           break;
	        }
	    }
	    
	    if(flag==1)
	    {
	        cout<<index<<endl;
	    }
	    else
	    {
	        cout<<-1<<endl;
	    }
    }
    
}
