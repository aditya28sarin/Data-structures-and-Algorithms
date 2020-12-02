#include<bits/stdc++.h>
using namespace std;


void swap(int *a, int *b)
{
	int temp_var;
	temp_var=*a;
	*a=*b;
	*b=temp_var;
}

class MinHeap{
	int *heap_array;
	int heap_capacity;
	int heap_size;
	
public:
	MinHeap(int heap_capacity);
	
	int parentNode(int index){return (index-1)/2;}
	
	int leftNode(int index){return (2*index)+1;}
	
	int rightNode(int index){return (2*index)+2;}
	
	int extractMin();
	
	void insertKey(int key);

	void decreaseKey(int index, int new_value);
	
	void minHeapify(int index);
	
	void deleteKey(int index);
};

MinHeap::MinHeap(int heap_capacity)
{
	heap_size=0;
	this->heap_capacity=heap_capacity;
	heap_array= new int[heap_capacity];
}

void MinHeap::insertKey(int key)
{
	if(heap_size == heap_capacity){
		cout<<"The Heap is at max capacity!";
		return;
	}
	
	heap_size++;
	int index = heap_size-1;
	heap_array[index]=key;
	
	while(index!=0 && heap_array[parentNode(index)]>heap_array[index])
	{
		swap(&heap_array[parentNode(index)], &heap_array[index]);
		index=parentNode(index);
	}
}

void MinHeap :: decreaseKey(int index, int new_value){
	
	heap_array[index]=new_value;
	
	while(index!=0 && heap_array[parentNode(index)]>heap_array[index]){
		swap(&heap_array[parentNode(index)], &heap_array[index]);
		index=parentNode(index);
	}
}


int MinHeap :: extractMin()
{
	if(heap_size<=0)
	{
		cout<<"Heap does not exist!"<<endl;
		return INT_MAX;
	}
	if(heap_size==1)
	{
		return heap_array[0];
	}

	int root= heap_array[0];
	heap_array[0]=heap_array[heap_size-1];
	heap_size--;
	
	minHeapify(0);
	
	return root;
}


void MinHeap::minHeapify(int index)
{
	int left_index=leftNode(index);
	int right_index=rightNode(index);
	int smallest=index;
	
	if(left_index<heap_size && heap_array[left_index]<heap_array[index])
	{
		smallest=left_index;
	}
	
	if(right_index<heap_size && heap_array[right_index]<heap_array[smallest])
	{
		smallest=right_index;
	}
	
	if(smallest!=index){
		swap(&heap_array[index], &heap_array[smallest]);
		minHeapify(smallest);
	}
}


void MinHeap::deleteKey(int index){
	decreaseKey(index,INT_MIN);
	extractMin();
}

int main() 
{ 
    MinHeap h(11); 
    h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
    h.decreaseKey(2, 1); 
    cout << h.getMin(); 
    return 0; 
} 


