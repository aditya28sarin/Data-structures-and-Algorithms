#include  <iostream> 
using namespace std;

int shellSort(int arr[], int n) 
{ 
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < n; i += 1) 
        { 
           
            int temp = arr[i]; 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
            {
                arr[j] = arr[j - gap]; 
            }
          
            arr[j] = temp; 
        } 
    } 
    return 0; 
} 

int main() 
{ 
 int n;
 cout<<"Enter the size of the array: "<<endl;
 cin>>n;
 int arr1[n],arr2[n];
 
 cout<<"Enter "<<n<<" integers in any order"<<endl;
 for(int i=0;i<n;i++)
 {
 cin>>arr1[i];
 arr2[i]=arr1[i];
 }
 
 cout<<endl<<"Before Sorting: "<<endl;
 for(int i=0;i<n;i++)
 {
 cout<<arr1[i]<<" ";
 }
 
 cout<<endl<<endl<<"SHELL SORT "<<endl;
 
 shellSort(arr1, n); // SHELL SORT CALLED HERE
   
 cout<<endl<<"After Sorting: "<<endl;
 for(int i=0;i<n;i++)
 {
 cout<<arr1[i]<<" ";
 }
 
   return 0; 
}