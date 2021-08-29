#include<iostream>
using namespace std;

int cutRod(int len[], int price[], int N, int L){
     
     int tb[N+1][L+1];
     for(int i=0;i<N+1;i++){
        for(int j=0;j<L+1;j++){
            if(i==0 || j==0){
                tb[i][j]=0;
            }
        }
    }

    for(int i=1;i<N+1;i++){
        for(int j=1;j<L+1;j++){
            if(len[i-1]<=j){
                tb[i][j]=max(price[i-1]+tb[i][j-len[i-1]], tb[i-1][j]);
            }else{
                tb[i][j]= tb[i-1][j];
            }
        }
    }

    return tb[N][L];
}



int main() 
{ 
    int len[] = {1,2,3,4,5,6,7,8};
    int price[]={1,5,8,9,10,17,17,20};
    int L=8; 
    int size = sizeof(len)/sizeof(len[0]); 
    cout<<"Maximum Obtainable Value is: "<<cutRod(len,price,size,L); 

    return 0; 
}