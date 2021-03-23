// URL: https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
#include<bits/stdc++.h>
using namespace std;
#define d 256

void search(char pat[], char txt, int q){

    int m = strlen(pat);
    int n = strlen(txt);

    int i,j;
    int p=0; //hash value for pattern
    int t=0; //hash value for text 
    int h=1; 

    for(int i=0;i<m-1;i++){
        h=(h*d)%q;
    }


    //hash value of pattern and the first window posn text
    for(int i=0;i<m;i++){
        p=(d*p + pat[i])%q;
        t=(d*t + txt[i])%q;
    }

    //slide pattern over the text one by one 

    for(int i=0;i<=n-m;i++){

        //check for hash value of pattern and current window
        if(p==t){
            
            //check chars one by one 
            for(j=0;j<m;j++){
                if(txt[i+j]!=pat[j]){
                    break;
                }
            }

            if(j==m){
                    cout<<"Pattern found at index "<<i<<endl;
            }
        }

        if(i<n-m){
            t=(d*(t-txt[i]*h)) + txt[i+m]%q;

            if(t<0){
                t=t+q;
            }
        }
    }
}



int main() 
{ 
	char txt[] = "GEEKS FOR GEEKS"; 
	char pat[] = "GEEK"; 
	int q = 101; // A prime number 
	search(pat, txt, q); 
	return 0; 
} 
