//User function Template for C++

// ar[] is the array
// n is the number of elements in array.
void print(int ar[], int n)
{

    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            cout<<ar[i]<<" ";
        }
        else
        {
            continue;
        }
    }

}
