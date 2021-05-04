#include<iostream>
using namespace std;

bool is SubsetSum(int set[], int n, int sum){
    int dp[n+1][sum+1];

    for(int i=0;i<n+1;i++){
        dp[i][0]=true;
    }

    for(int i=0;i<sum+1;i++){
        dp[0][i]=false;
    }
}

int main() 
{ 
int set[] = {3, 34, 4, 12, 5, 2}; 
int n = sizeof(set)/sizeof(set[0]); 
int sum=0;
for(int i=0;i<n;i++){
    sum+=set[i];
}

if(sum%2!=0){
    cout<<"Not Present";
}
else{
    if (isSubsetSum(set, n, sum/2) == true) 
	    printf("Found a subset with given sum"); 
    else
	    printf("No subset with given sum"); 
}
return 0; 
} 