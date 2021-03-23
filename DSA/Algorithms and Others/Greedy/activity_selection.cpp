// URL: geeksforgeeks.org/activity-selection-problem-greedy-algo-1/

#include <iostream>
using namespace std;

//if array is not sorted 
struct Activity {
    int start, int finish;
};

bool activityCompare(Activity a, Activity b){
    return(a.finish < b.finish);
}

void printMxActivities(Activity arr[], int n){
    sort(arr, arr+n, activityCompare);

     int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";
 
    for (int j = 1; j < n; j++)
    {
      if (arr[j].start >= arr[i].finish)
      {
          cout << "(" << arr[j].start << ", "
              << arr[j].finish << "), ";
          i = j;
      }
    }
}

int main()
{
    Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},
                                       {5, 7}, {8, 9}};
    int n = sizeof(arr)/sizeof(arr[0]);
    printMaxActivities(arr, n);
    return 0;
}


//Sorted already by finish time 
void printMaxActivities(int s[], int f[], int n){

    int i=1,j=0;
    cout<<0;
    while(i<n){
        if(s[i]>f[j]){
            j=i;
            cout<<" "<<j;     
        }
    }
}

int main()
{
    int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s, f, n);
    return 0;
}