#include <bits/stdc++.h>
using namespace std;




int checkPangram(string str, int k)
{
    if(str.length()<26)
        return 0;
   vector <bool> vt(26,false);
   int index;
   
   for(int i =0; i<str.length(); i++)
   {
       
    if(str[i]>='a' && str[i]<='z')
        index=str[i]-'a';
        
    else if(str[i]>='A' && str[i]<='Z')
        index=str[i]-'A';
    else
    continue;
    
    vt[index]=true;
        
   }
   int c=0;
   for(int i=0;i<vt.size();i++)
   {
       
       if(vt[i]==false)
            c++;
   }
   
  
  if(c>k)
    return 0;
  else
    return 1;
    
}

int main() {
	int cases;
	
	cin>>cases;
	int k;
	while(cases--)
	{
	    
	    string str;
	    
	    cin>>str;
	    
	    cin>>k;
	    
	    int ans= checkPangram(str,k);
	    cout<<ans<<endl;
	}

	return 0;
}