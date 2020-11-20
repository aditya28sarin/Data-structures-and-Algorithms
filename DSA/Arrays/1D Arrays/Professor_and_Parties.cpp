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
	    
	    unordered_set <int> st;
	    
	    for(int i=0;i<n;i++)
	    {
	        st.insert(arr[i]);
	    }
	    
	    if(st.size()==n)
	    {
	        cout<<"GIRLS"<<endl;
	    }
	    else
	    {
	        cout<<"BOYS"<<endl;
	    }
	    
	}
	return 0;
}