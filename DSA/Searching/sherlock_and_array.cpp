// Watson gives Sherlock an array of integers. His challenge is to find an element of the array such that the sum of all elements to the left 
//is equal to the sum of all elements to the right. For instance, given the array ,  is between two subarrays that sum to . If your starting array is , 
//that element satisfies the rule as left and right sum to .

// You will be given arrays of integers and must determine whether there is an element that meets the criterion.

// Function Description

// Complete the balancedSums function in the editor below. It should return a string, either YES if there is an element meeting the criterion or NO otherwise.

// balancedSums has the following parameter(s):

// arr: an array of integers
// Input Format

// The first line contains , the number of test cases.

// The next  pairs of lines each represent a test case.
// - The first line contains , the number of elements in the array .
// - The second line contains  space-separated integers  where .

// Output Format

// For each test case print YES if there exists an element in the array, such that the sum of the elements on its left is equal to the sum of the elements on its right;
// otherwise print NO.

// Sample Input 0

// 2
// 3
// 1 2 3
// 4
// 1 2 3 3
// Sample Output 0

// NO
// YES


-------------------------------------------------------------------------------------------------------
						CODE
-------------------------------------------------------------------------------------------------------


//O(n^2) solution
//calculates left and righr side of the array sum
string balancedSums(vector<int> arr) 
{
    int i=0;
    bool flag=false;
    int left_sum=0;
    int right_sum=0;
    while(i<arr.size())
    {
        left_sum=0;
        right_sum=0;
        int j=i-1;
        while(j>=0)
        {
            left_sum=left_sum+arr[j];
            j--;
        }
        
        
        int k=i+1;
        while(k<arr.size())
        {
            right_sum=right_sum+arr[k];
            k++;
        }
        
        if(left_sum==right_sum)
        {
            flag=true;
            break;
        }
        i++;
    }
    
    if(flag==true)
    {
        return "YES";
    }
    else
        return "NO";
}


//O(n)
string balancedSums(vector<int> arr) 
{
    int initial_sum=0;
    int sum=0;

    for(int x:arr)
        sum=sum+x;

    for(int y:arr)
    {
        if(2*initial_sum==sum-y)
        {
            return "YES";
        }
        initial_sum=initial_sum+y;
    }
    return "NO";
}