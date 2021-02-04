// URL: https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

#include <bits/stdc++.h> 
using namespace std;


void computeLPS(int pat[], int m, int lps[]){
    int i =0;

    lps[0]=0;

    int j=1;
    while(j<m){
        if(pat[j]==pat[i]){
            i++;
            lps[i]=j;
            j++;
        }else{
            if(j!=0){
                i=lps[i-1];
            }else{
                lps[j]=0;
                j++;
            }
        }
    }
}


KMPSearch(int pat[], int txt[]){
    int n = strlen(txt);
    int m = strlen(pat);

    int lps[m];

    computeLPS(pat, m, lps);

     int i = 0; 
    int j = 0; 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) { 
            printf("Found pattern at index %d ", i - j); 
            j = lps[j - 1]; 
        } 
        else if (i < N && pat[j] != txt[i]) { 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 

}



int main() 
{ 
    char txt[] = "ABABDABACDABABCABAB"; 
    char pat[] = "ABABCABAB"; 
    KMPSearch(pat, txt); 
    return 0; 
}