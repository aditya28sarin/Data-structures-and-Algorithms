
//User function Template for C++

//Complete this function. it1 points to vector.begin(), it2 points to vector.end()
void iter(vector<int>::iterator it1,vector<int>::iterator it2)
{
    for(it1;it1!=it2;it1++)
    {
        cout<<*it1<<" ";
    }
    cout<<endl;
}
