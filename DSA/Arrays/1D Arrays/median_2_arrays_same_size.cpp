// URL: https://www.geeksforgeeks.org/median-of-two-sorted-arrays/

#include <bits/stdc++.h>
using namespace std;


int getMedian(int arr1[], int arr2[], int n){
	
	int i=n-1;
	int j=0;
	while(arr1[i]>arr2[j] && i<n && j>-1){
		swap(arr1[i], arr2[j]);
		i--;
		j++;
	}
	
	sort(arr1,arr1+n);
	sort(arr2,arr2+n);
	
	return (arr1[n-1]+arr2[0])/2;
} 

int main()
{
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};
 
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is "
             << getMedian(ar1, ar2, n1) ;
    else
        cout << "Doesn't work for arrays"
             << " of unequal size" ;
    getchar();
    return 0;
}