#include<bits/stdc++.h>
using namespace std;

void add_pair(vector<pair<string,pair<int,int>>> &A, string str,int x, int y)
{



//    pair<string,pair<int,int>> p1;


    A.push_back({str,{x,y}});


}

int get_size(vector<pair<string,pair<int,int>>> &A)
{

return A.size();
}

void print_values(vector<pair<string,pair<int,int>>> &A)
{

    for(int i=0;i<A.size();i++)
        {

            cout<< A[i].first<<" ";
            cout<< A[i].second.first<<" "<<A[i].second.second<<" ";

        }
}


bool cmp (pair<string, pair<int,int>> a, pair<string,pair<int,int>> b)
{
    if(a.second.first<b.second.first)
    {
        return 1;
    }
    if(a.second.first==b.second.first && a.second.second<b.second.second)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
void sort_pair(vector<pair<string,pair<int,int>>> &A)
{
    sort(A.begin(),A.end(), cmp);
}


int main()
{

    int cases;
    cin>>cases;
    while(cases--)
    {

        vector<pair<string,pair<int,int>>> A;
        int q;
        cin>>q;

        while(q--)

        {
            char c;
             cin>>c;

            if(c=='a')
            {

                string name;
                cin>>name;
                int x,y;

                cin>>x>>y;

                add_pair(A,name,x,y);

            }
            if(c=='b')
            {
                int br=get_size(A);
                cout<<br<<" ";
            }

            if(c=='c')

            {
                print_values(A);
            }
            if (c=='d')
            {

                sort_pair(A);
            }
        }
        cout<<endl;
    }
    return 0;

}


