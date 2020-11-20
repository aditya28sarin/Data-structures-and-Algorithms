#include<iostream>
using namespace std;


//method 1 (Temp Array)
void rotateArrayTempArray(int arr[],int array_size, int rotation_size)
{
    int temp[rotation_size];
    for(int i=0;i<rotation_size;i++)
        temp[i]=arr[i];
        
    for(int i=0;i<array_size-2;i++)
        arr[i]=arr[i+rotation_size];

    for(int i=array_size-rotation_size,j=0;i<=array_size;i++,j++)
        arr[i]=temp[j];
    
    for(int i=0;i<array_size;i++)
         cout<<arr[i]<<" ";

}

//method 2 (Rotate One By One)
void rotateOneByOne(int arr[],int array_size, int rotation_size)
{
    int temp,i,j;
   
    for(j=0;j<rotation_size;j++)
    {
        temp =arr[0];
     for(i =0;i<array_size-1;i++)
        {
           arr[i]=arr[i+1];
        }
        arr[i]=temp;
    }
    for(int i=0;i<array_size;i++)
         cout<<arr[i]<<" ";
}
//method 3 (Reversal Algorithm)
int* reversalAlgorithm(int arr[], int start, int end)
{

    while(start<end)
    {
        int temp = arr[start];
        arr[start]=arr[end];
        arr[end]=temp;

        start++;
        end--;
    }   
}

//method 4 (Juggling Algorithm)
int gcd(int arr_size, int rotation_size);
void jugglingAlgorithm(int arr[], int arr_size, int rotation_size)
{
    int gcd_val=gcd(arr_size,rotation_size);
    int i,j;
    for(i=0; i<gcd_val;i++)
    {
        int temp =arr[i];
        j=i;

        while(1)
        {
            int k =j+rotation_size;

            if(k>=arr_size)
                k=k-arr_size;

            if(k==i)
                break;
            
            arr[j]=arr[k];
            j=k;
        }
        arr[j]=temp;
    }


    for(int i=0;i<arr_size;i++)
        cout<<arr[i]<<" ";
}

int gcd(int arr_size, int rotation_size)
{
    if(arr_size==0)
        return rotation_size;

    if(rotation_size==0)
        return arr_size;

    if(arr_size==rotation_size)
        return arr_size;

    if(arr_size>rotation_size)
        return gcd(arr_size-rotation_size,rotation_size);
    else
    {
        return gcd(arr_size,rotation_size-arr_size);
    }
}




int main()
{
    int array_size;
    cin>>array_size;
    int arr[array_size];
    for(int i=0;i<array_size;i++)
    {
        cin>>arr[i];
    }
    int rotation_size;
    cin>>rotation_size;

    //method 1
    //rotateArrayTemp(arr,array_size, rotation_size);

    //method 2
    //rotateArrayTempVar(arr,array_size,rotation_size);
    
    //method 3 
    // int *res=reversalAlgorithm(arr,0,rotation_size-1);
    // res=reversalAlgorithm(arr,rotation_size,array_size-1);
    // res=reversalAlgorithm(arr,0,array_size-1);
    // for(int i=0;i<array_size;i++)
    //     cout<<arr[i]<<" ";

    //method 4 
    jugglingAlgorithm(arr,array_size,rotation_size);


}