// URL: https://www.geeksforgeeks.org/c-program-hashing-chaining/

#include<bits/stdc++.h>
using namespace std;

class Hash{
	int BUCKET;
	
	list<int> *table;
	
	public:
		Hash(int b);
		void insertItem(int x); 
		void deleteItem(int x);
		
		int hashFunction(int x){
			return x%BUCKET;
		}
};

Hash::Hash(int b){
	this->BUCKET = b;
	table = new list<int>[BUCKET];	
}

void Hash::insertItem(int key){
	int index = hashFunction(key);
	table[index].push_back(key);
}

void Hash::deleteItem(int key){
	int index = hashFunction(key);
	
	list<int> :: iterator i;
	
	for(i=table[index].begin(); i!=table[index].end();i++){
		if(*i==key){
			break;
		}
	}
	
	if (i != table[index].end()) 
		table[index].erase(i); 
}

void Hash::displayHash() { 
  for (int i = 0; i < BUCKET; i++) { 
    cout << i; 
    for (auto x : table[i]) 
      cout << " --> " << x; 
    cout << endl; 
  } 
} 


int main() 
{ 
  // array that contains keys to be mapped 
  int a[] = {15, 11, 27, 8, 12}; 
  int n = sizeof(a)/sizeof(a[0]); 
  
  // insert the keys into the hash table 
  Hash h(7);  
  for (int i = 0; i < n; i++)  
    h.insertItem(a[i]);   
  
  // delete 12 from hash table 
  h.deleteItem(12); 
  
  // display the Hash table 
  h.displayHash(); 
  
  return 0; 
 
}