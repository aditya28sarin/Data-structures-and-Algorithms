// URL: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	  
    int dead;  
    int profit; 
}; 



bool comp(Job a, Job b){
    return (a.profit > b.profit);
}

pair<int,int> JobScheduling(Job arr[], int n) 
{ 
   sort(arr,arr+n,comp);
   
   int max_deadline = arr[0].dead;
   
   for(int i=1;i<n;i++){
       max_deadline = max(max_deadline, arr[i].dead);
   }
   
   int deadline_array[max_deadline + 1];
   
   for(int i=0;i<max_deadline;i++){
        deadline_array[i]=-1;       
   }
   
   int countJobs = 0; 
   int jobProfit = 0;
   
   for(int i=0;i<n;i++){
       for(int j=arr[i].dead;j>0;j--){
           if(deadline_array[j]==-1){
               deadline_array[j]=i;
               countJobs++;
               jobProfit+=arr[i].profit;
               break;
           }
       }
   }
   
   return make_pair(countJobs,jobProfit);
} 




int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
        int n;

        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        pair<int,int> ans = JobScheduling(arr, n);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
	return 0; 
}
