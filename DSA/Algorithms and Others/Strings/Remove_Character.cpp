using namespace std;

int main() {
	
	int cases;
	cin>>cases;
	
	while(cases--)
	{
	    string s1;
	    string s2;
	 
	    cin>>s1;
	    cin>>s2;

	    unordered_set <char> us;
	    
	    for(int i=0;i<s2.length();i++)
	    {
	        us.insert(s2[i]);
	    }
	    int i=0;
	    while(i<s1.length())
	    {
	        if(us.find(s1[i])!=us.end())
	        {
	            s1.erase(i,1);
	        }
	        else
	            i++;
	    }
	    
	    for(int i=0;i<s1.length();i++)
	    {
	        cout<<s1[i];
	   }
	   cout<<endl;
	}
	return 0;
}