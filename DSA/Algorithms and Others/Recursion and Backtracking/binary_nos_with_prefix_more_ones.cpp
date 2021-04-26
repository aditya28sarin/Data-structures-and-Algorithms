#include<bits/stdc++.h>
using namespace std;

void solve(int n, int ones, int zeros, string op){
    if(n==0){
        cout<<op<<" ";
        return;
    }

    string op1=op;
    op1.push_back('1');
    
    solve(n-1,ones+1,zeros,op1);

    if(ones>zeros){
        string op2=op;
        op2.push_back('0');
        solve(n-1,ones,zeros+1,op2);
    }

    return;
}


int main(){
    int n = 3;
    string op="";
    int ones=0;
    int zeros=0;
    solve(n,ones,zeros,op);
}