

///my try with jump search

//#include<iostream>
//#include<cmath>
//using namespace std;

//int jumpSearch(int arr[],int blk, int n, int x)
//{
//    int m=blk;
//    int flag=0;
//    while(m<=n-1)
//    {
//        int cp=0;
//        if(arr[m]==x)
//        {
//            return m;
//            flag=1;
//        }
//        if(arr[m]>x)
//        {
//            for(int i=m;i>m-blk;i--)
//            {
//                if(arr[i]==x)
//                {
//                    return i;
//                    flag=1;
//                    break;
//                }
//                else
//                {
//                    cp++;
//                    if(cp==blk)
//                        m=m-4;
//                }
//            }
//        }
//        else if(arr[m]<x)
//        {
//            for(int i=m;i<m+blk;i++)
//            {
//                if(arr[m]==x)
//                {
//                    return i;
//                    flag=1;
//                    break;
//                }
//                else
//                {       cp++;
//                    if(cp==blk)
//                    m=m+blk;
//                }
//            }
//        }
//        if(flag==1)
//        {
//            break;
//        }
//    }
//
//}
//
//int main()
//{
//    int n=16;
//    int blk=4;
//    int x=34;
//    int arr[n]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
//    int ans=jumpSearch(arr,blk,n,x);
////    int index=jumpSearch(arr,x,n);
//   //cout<<index<<endl;
//cout<<ans<<endl;
//
//}





///Jump Search original

#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(int L[], int length, int key){

int left=0;
int right=sqrt(length);

while(right<length && L[right]<=key) //it checks if key is in that block or not, if less then it is not the right block
{

left=right;
right=right+sqrt(length);

if(right>length-1)
{

    right=length;
}

}

//we are in the right block
for(int i=left;i<right;i++)
{

     if(L[i]==key)
        return i;
}




}

int main()
{

    int L[] = {0, 1, 2, 3, 4, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int length = sizeof(L) / sizeof(L[0]);

    int key = 34;

    int x;
    if((x = jumpSearch(L, length, key)) == -1 ){

        cout << "Key doesn't exist" << endl;

    } else {

        cout << "The position of Key is " << x << endl;

    }
}

