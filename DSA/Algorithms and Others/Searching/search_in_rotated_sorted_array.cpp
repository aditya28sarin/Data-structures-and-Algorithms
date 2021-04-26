#include<bits/stdc++.h>
using namespace std;

int findMin(int arr[], int n){
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = low + (high-low)/2;
        int next=(mid+1)%n;
        int prev=(mid+n-1)%n;

        if(arr[mid]<=arr[prev] && arr[mid]<=arr[next]){
            return mid;
        } 

        else if(arr[mid]<=arr[high]){
            high=mid-1;
        }

        else if(arr[mid]>=arr[low]){
            low=mid+1;
        }
    }

    return -1;
}


    int BinSearch(int arr[],int low, int high, int element){
        
        while(low<=high){
            int mid = low + (high-low)/2;

            if(arr[mid]==element){
                return mid;
            }

            else if(arr[mid]<=element){
                low=mid+1;
            }

            else if(arr[mid]>element){
                high=mid-1;
            }
        }

        return -1;
    }

int main(){
    int arr[8]={11,12,15,18,2,5,6,8};
    int element = 15;
    int n=8;
    int min = findMin(arr,8);

    int x=BinSearch(arr,0,min-1,element);
    int y=BinSearch(arr,min,n-1,element);

    if(x==-1){
        cout<<y;
    }else{
        cout<<x;
    }
}