// An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.
// Examples : 

// Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
// Output: -12 -13 -5 -7 -3 -6 11 6 5

-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------

using namespace std;

int main() {
	int cases;
	cin>>cases;
	while(cases--)
	{
	    vector<int> vt;
	    queue<int> q1;
	    queue<int> q2;
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    int i=0;
	    while(i<n)
	    {
	        if(arr[i]>=0)
	        {
	            q1.push(arr[i]);
	        }
	        else
	        {
	            q2.push(arr[i]);
	        }
	        i++;
	    }
	    
	    while(!q1.empty() && !q2.empty())
	    {
	        vt.push_back(q1.front());
	        vt.push_back(q2.front());
	        q1.pop();
	        q2.pop();
	    }
	    
	    for(int i =0;i<vt.size();i++)
	        cout<<vt[i]<<" ";
	        cout<<endl;
	}
	return 0;
}