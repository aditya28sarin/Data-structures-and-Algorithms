// URL: https://www.geeksforgeeks.org/double-hashing/

#include<bits/stdc++.h>
using namespace std;

#define table_size 13
#define prime 7


class DoubleHash{
    public:
        int* hashTable;
        int curr_size;

        bool isFull()
        {
            return (curr_size == table_size); 
        }
        
        int hash1(int key)
        {
            return (key % table_size);
        }

        int hash2(int key)
        {
            return (prime - (key%prime));
        }

        DoubleHash()
        {
            hashTable =new int[table_size];
            curr_size=0;
            for(int i =0 ; i<table_size;i++)
            {
                hashTable[i]=-1;
            }
        }

        void insertHash(int key)
        {
            if(isFull())
            return;
            
            int index = hash1(key);

            if(hashTable[index]!=-1)
            {
                int index1= hash2(key);
                int i=1;
                while(1)
                {
                    int new_index=(index+ i*index1)%table_size;

                    if(hashTable[new_index]==-1)
                    {
                            hashTable[new_index]=key;
                            break;
                    }
                    i++;
                }
            }
            else
            {
                hashTable[index]=key;
                curr_size++;
            }
        }


    void search(int key)
    {
        int index1= hash1(key);
        int index2=hash2(key);
        int i = 0;
        while(hashTable[index1 + i*index2]!=key)
        {
            if(hashTable[index1 + i*index2]==-1)
            {
                cout<<key<<" does not exist"<<endl;
                return;
            }
            i++;
        }
            cout<<key<<" found!"<<endl;
            
    }
    
    void displayHash()
    {
        for(int i=0;i<table_size;i++)
        {
        cout << i << " --> " << hashTable[i] << endl;  
        }
    }
};



int main()
{
    int a[] = { 19, 27, 36, 10, 64 }; 
    int n = sizeof(a) / sizeof(a[0]); 
  
    // inserting keys into hash table 
    DoubleHash h; 
    for (int i = 0; i < n; i++) { 
        h.insertHash(a[i]); 
    } 
    // searching some keys 
    h.search(36); // This key is present in hash table 
    h.search(10); // This key does not exist in hash table 
    // display the hash Table 
    h.displayHash(); 
}