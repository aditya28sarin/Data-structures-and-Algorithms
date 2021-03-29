// URL: https://www.youtube.com/watch?v=eTaWFhPXPz4&t=1369s


//Using Disjoint Set (Not optimized)
#include<bits/stdc++.h>
using namespace std;

int find(vector<int>& dsuf,int element){

        if(dsuf[element]==-1){
            return element;
        }else{
            return find(dsuf,dsuf[element]);
        }
}

void unionDS(vector<int>& dsuf, int fromP, int toP){
    fromP=find(dsuf,fromP);
    toP=find(dsuf,toP);
    dsuf[fromP]=toP;
}

bool detectCycle(vector<pair<int,int>>& vt,vector<int>& dsuf, int V){
    
    for(auto pair:vt){
        
        int fromP = find(dsuf,pair.first);
        int toP= find(dsuf,pair.second);

        if(fromP==toP){
            return true;
        }
        unionDS(dsuf,fromP,toP);
    }
    return false;
}


//using Disjoint Set (With Path Compression and Union by Rank)
struct node{
    int parent;
    int rank;
};

int find1(vector<node>& dsuf1, int element){
    if(dsuf1[element].parent==-1){
        return element;
    }else{
        return dsuf1[element].parent = find1(dsuf1,dsuf1[element].parent);
    }
}

void unionDS1(vector<node>& dsuf1, int fromP, int toP){

    if(dsuf1[fromP].rank > dsuf1[toP].rank){
        dsuf1[toP].parent = fromP;
    }else if(dsuf1[fromP].rank < dsuf1[toP].rank){
        dsuf1[fromP].parent = toP;
    }else{
        dsuf1[fromP].parent = toP;   
        dsuf1[toP].rank +=1;
    }
    
}


bool detectCycle1(vector<pair<int,int>>& vt, vector<node>& dsuf1, int V){
    for(auto pair:vt){
        
        int fromP = find1(dsuf1,pair.first);
        int toP= find1(dsuf1,pair.second);

        if(fromP==toP){
            return true;
        }
        unionDS1(dsuf1,fromP,toP);
    }
    return false;    
}



int main(){

    
    int V=5;
    vector<pair<int,int>> vt;
    vt.push_back({0,1});
    vt.push_back({1,2});
    vt.push_back({2,3});
    vt.push_back({3,0});

    vector<int> dsuf (V,-1);

    if(detectCycle(vt,dsuf,V)){
        cout<<"Graph 1 contains a cycle.";
    }else{
        cout<<"Graph 1 does not contain a cycle.";
    }

    vector<node> dsuf1;

    dsuf.resize(V); 

    for(int i=0;i<V;i++){
        dsuf1[i].parent = -1;
        dsuf1[i].rank = 0;
    }

    if(detectCycle1(vt,dsuf1,V)){
        cout<<"Graph 2 contains a cycle.";
    }else{
        cout<<"Graph 2 does not contain a cycle.";
    }
}