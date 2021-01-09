#include <iostream>
using namespace std;


class Heap {
private:
	int* heap;
	int capacity;
	int currentSize;

	void changesize(int *&a, const int oldsize, const int newsize)
	{
		int *temp = new int[newsize];
		int number = oldsize;
		copy(a, a + number, temp);
		delete[]a;

		a = temp;
	}
	void swap(int* a, int *b) {
		int t = *a;
		*a = *b;
		*b = t;
	}



public:

	
	Heap(int Capacity=5) : capacity(Capacity){
		heap = new int[Capacity];
		currentSize = 0;
	}
	
	~Heap() {
		delete[] heap;
	}

	void printheap(){
 	 if (currentSize == 0)
  	 cout << "error" << endl;
  	else
 	 {
 	  for (int i = 0; i < currentSize; i++)
  	 {
   	  cout << heap[i] <<" ";
 	  }
	cout<<endl;
 	 }
	 } 
	
	void Insert(int val) {
		
		if (currentSize >= capacity) {
			changesize(heap, capacity, capacity * 2);
			capacity = 2 * capacity;
		}
		
		int mPos = currentSize++;
		heap[mPos] = val;
		
		int parPos = (mPos - 1) / 2;
		while (heap[mPos]>heap[parPos]) {
			swap(&heap[mPos], &heap[parPos]);
			mPos = parPos;
			parPos = (mPos - 1) / 2;
		}
	}

	int pop() {
		if (currentSize <= 0) {
			printf("Heap is Empty!!!\n");
			return NULL;
		}
		int returnVal = heap[0];
		
		swap(&heap[0], &heap[currentSize - 1]);
	
		heap[currentSize - 1] = NULL;
		currentSize--;
		
		int root = 0;
		int leftChild;
		int rightChild;

		while (root <= currentSize - 1) {
			leftChild = (root + 1) * 2 - 1;
			rightChild = (root + 1) * 2;

			if (leftChild >= currentSize) {
				
				break;
			}
			else if (rightChild >= currentSize) {
				
				if (heap[leftChild] > heap[root]) {
					swap(&heap[leftChild], &heap[root]);
					root = leftChild;
				}
				else break;
			}
			else {
				
				if (heap[leftChild] > heap[root] && heap[rightChild] > heap[root]) {
					if (heap[leftChild]<heap[rightChild]) {
						swap(&heap[rightChild], &heap[root]);
						root = rightChild;
					}
					else {
						swap(&heap[leftChild], &heap[root]);
						root = leftChild;
					}
				}
				else if (heap[leftChild] > heap[root]) {
					swap(&heap[leftChild], &heap[root]);
					root = leftChild;
				}
				else if (heap[rightChild] > heap[root]) {
					swap(&heap[rightChild], &heap[root]);
					root = rightChild;
				}
				else {
					break;
				}
			}

		}
		return returnVal;

	}
	int GetTop() {
		if (currentSize >= 1)	return heap[0];
		else return -1;
	}
	int GetPop(int k){
 	 int arr[1000000];
 	 for (int i = 0; i < k-1; i++)
 	 {
   
 	  int a = pop();
   arr[i] = a;
	  }
  int n = pop();
  for (int i = k - 2; i >= 0; i--)
  {
   Insert(arr[i]);
  }
  return n;
 } 

int getSize()
{return currentSize;}

void GetTop(int k){
	int arr[1000000];
	for(int i=0;i<k;i++)
	{int a=pop();	
	arr[i]=a;}
cout<<arr[k-1]<<endl;
for(int i=k-1;i>=0;i--)
{Insert(arr[i]);}
return;
	}
};



int main() {

	Heap heap;
	char k;
	int num;
	cin>>k;

	while(!cin.eof())
	{


		if(k=='I')
		{
		cin>>num;
if(num<0) {cout<<"error"<<endl;
cin>>k;
continue;}
		else{heap.Insert(num);
		cout<<"done"<<endl;
		cin>>k;
		continue;}
		}

		else if (k=='D'){
		cin>>k;
if(heap.GetTop()==-1){cout<<"error"<<endl;
cin>>k;
continue;}
		if(k=='D'||k=='I'||k=='T'||k=='P')
		{
		num=heap.pop();
		cout<<"done"<<endl;
		continue;
		}
		else{
		num=k-'0';
		if(num>heap.getSize())
		{cout<<"error"<<endl;
		cin>>k;
		continue;
		}
		else {num=heap.GetPop(num);
		cout<<"done"<<endl;
		cin>>k;
		continue;}
		}
		}

		else if (k=='T'){
		cin>>k;
		if(k=='D'||k=='I'||k=='T'||k=='P')
		{
		num=heap.GetTop();
		if(num==-1) cout<<"error"<<endl;
		else cout<< num <<endl;
		continue;
		}
		else{
num=k-'0';
if(num>heap.getSize()) {cout<<"error"<<endl; 
cin>>k; 
continue;}
heap.GetTop(num);
		cin>>k;
		continue;}
		}
	
		else if (k=='P'){
		heap.printheap();
		cin>>k;
		continue;
		}
		else{
		cout<<"sorry not yet"<<endl;
		cin>>k;
		continue;}

	}
return 0;
}
