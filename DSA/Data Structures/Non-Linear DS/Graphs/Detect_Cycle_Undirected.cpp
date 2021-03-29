// URL: https://www.youtube.com/watch?v=eTaWFhPXPz4&t=1369s

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

int main(){

    
    int V=5;
    vector<pair<int,int>> vt;
    vt.push_back({0,1});
    vt.push_back({1,2});
    vt.push_back({2,3});
    vt.push_back({3,0});

    vector<int> dsuf (V,-1);

    if(detectCycle(vt,dsuf,V)){
        cout<<"Graph contains a cycle.";
    }else{
        cout<<"Graph does not contain a cycle.";
    }
}