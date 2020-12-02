include<bits/stdc++.h>
using namespace std;


void swap(int *a, int *b)
{
	int temp_var;
	temp_var=*a;
	*a=*b;
	*b=temp_var;
}

class MaxHeap{
	int *heap_array;
	int heap_capacity;
	int heap_size;
	
public:
	MaxHeap(int heap_capacity);
	
	int parentNode(int index){return (i-1)/2;}
	
	int leftNode(int index){return (2*i)+1;}
	
	int rightNode(int index){return (2*i)+2;}
	
	void insertKey(int key);

	void increaseKey(int index, int new_value);
	
	void extractMax();
	
	void maxHeapify(int index);
	
	int getMax(){return heap_array[0];}
	
	void deleteKey(int index);
};

MaxHeap::MaxHeap(int heap_capacity)
{
	heap_size=0;
	this->heap_capacity=heap_capacity;
	heap_array= new int[heap_capacity];
}

void MaxHeap::insertKey(int key)
{
	if(heap_size == heap_capacity){
		cout<<"The Heap is at max capacity!";
		return;
	}
	
	heap_size++;
	int index = heap_size-1;
	heap_array[index]=key;
	
	while(index!=0 && heap_array[parentNode(index)]<heap_array[index])
	{
		swap(&heap_array[parentNode(index)], &heap_array[index]);
		index=parentNode(index);
	}
}


void MaxHeap :: increaseKey(int index, int new_value){
	
	heap_array[index]=new_value;
	
	while(index!=0 && heap_array[parentNode(index)]<heap_array[index]){
		swap(&heap_array[parentNode(index)], &heap_array[index]);
		index=parentNode(index);
	}
}


int MaxHeap :: extractMax(int index)
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
	
	maxHeapify(0);
	
	return root;
}



void MaxHeap::MaxHeapify(int index)
{
	int left_index=left(index);
	int right_index=right(index);
	int largest=index;
	
	if(left_index<heap_size && heap_array[left_index]>heap_array[index])
	{
		largest=left_index;
	}
	
	if(right_index<heap_size && heap_array[right_index]>heap_array[largest])
	{
		largest=right_index;
	}
	
	if(largest!=index){
		swap(&heap_array[index], &heap_array[largest]);
		maxHeapify(largest);
	}
}


void MaxHeap::deleteKey(int index){
	increaseKey(index,INT_MAX);
	extractMax();
}
