
//User function Template for C++

vector<int> sortVector(vector<int>v)
{
   sort(v.begin(),v.end());
    return v;
}
vector<int> reverseVector(vector<int>v)
{

    int temp;
     for(int i=0;i<v.size()/2;i++)
     {
         temp=v[i];
         v[i]=v[v.size()-1-i];
         v[v.size()-1-i]=temp;
     }
    return v;
}
