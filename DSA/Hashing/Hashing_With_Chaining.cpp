#include<bits/stdc++.h>
using namespace std;


class Hash{
  public:
    int buckets;
     list <int> *table;
    
    Hash(int b)
    {
        this->buckets=b;
        table = new list <int>[buckets];
    }
  
    void insertItem(int x)
    {
        int index = hashFunction(x);
        table[index].push_back(x);
    }
  
    void deleteItem(int x)
    {
        int index = hashFunction(x);

        list <int> :: iterator i;

        for(i=table[index].begin(); i!=table[index].end();i++)
        {
            if(*i==x)
                break;
        }

        if(i!=table[index].end())
        {
            table[index].erase(i);
        }
    }

    void displayHash()
    { 
        for(int i=0;i<buckets;i++){
            cout<<i;
        list<int>  :: iterator j;
        for (j=table[i].begin();j!=table[i].end();j++)
        {
            cout << " --> " << *j; 
        } 
        
        cout << endl; 
         }
    }

    
    int hashFunction(int x) { 
        return (x % buckets); 
    } 
  
};

int main() 
{ 
  // array that contains keys to be mapped 
  int a[] = {15, 11, 27, 8, 12}; 
  int n = sizeof(a)/sizeof(a[0]); 
  
  // insert the keys into the hash table 
  Hash h(7);   // 7 is count of buckets in 
               // hash table 
  for (int i = 0; i < n; i++)  
    h.insertItem(a[i]);   
  
  // delete 12 from hash table 
  h.deleteItem(12); 
  
  // display the Hash table 
  h.displayHash(); 
  
  return 0; 
 
}