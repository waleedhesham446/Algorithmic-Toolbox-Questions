#include<iostream>

using namespace std;

void countSort(int* A, int n){
	
	int max = A[0];
	for(int i = 1; i < n; i++){
		if(A[i] > max)
			max = A[i];
		if(A[i] <= 0)
			return;
	}

	int* count = new int [max+1];
	for(int i = 1; i <= max; i++)
		count[i] = 0;

	for(int i = 0; i < n; i++)
		count[A[i]]++;

	int l = 1, k = 0;
	while(l <= max){
		for(int j = 0; j < count[l]; j++){
			A[k++] = l;
		}
		l++;
	}

	delete [] count;
}

void merge(int* B, int* C, int n1, int n2, int* A){
	int i = 0, j = 0, k = 0;

	while(i < n1 && j < n2){

		//if(B[i] >= C[j])		//	Descending
		if(B[i] <= C[j])		//	Ascending
		{
			A[k] = B[i];
			i++;
		}else{
			A[k] = C[j];
			j++;
		}
		k++;
	}

	while(i < n1 )
		A[k++] = B[i++];

	while(j < n2 )
		A[k++] = C[j++];
}

void mergeSort(int* A, int n){

	if(n == 1)
		return;

	int m = n / 2;

	int* B = new int[m + n%2];
	int* C = new int[m];

	for(int i = 0; i < m + n%2; i++)
		B[i] = A[i];
	int j = 0;
	for(int i = m + n%2; i < n; i++)
		C[j++] = A[i];

	mergeSort(B, m + n%2);
	mergeSort(C, m);

	merge(B, C, m + n%2, m, A);

	delete []B;
	delete []C;
}

void selectionSort(int* A, int n){

	for(int i = 0; i < n-1; i++){
		int minIndex = i;

		for(int j = i + 1; j < n; j++)
			//if(A[j] > A[minIndex])		//	Descending
			if(A[j] < A[minIndex])		//	Ascending
				minIndex = j;
		swap(A[i], A[minIndex]);
	}
}

void bubbleSort(int* A, int n){
	for(int i = 0; i < n-1; i++){
		bool sorted = true;

		for(int j = 0; j < n-i-1; j++)
			//if(A[j+1] > A[j])		//	Descending
			if(A[j+1] < A[j])		//	Ascending
			{
				swap(A[j+1], A[j]);
				sorted = false;
			}

		if(sorted)
			return;
	}
}

void insertionSort(int* A, int n){
	int key, j;
	for(int i = 1; i < n; i++){
		j = i - 1;
		key = A[i];
		//while(j >= 0 && A[j] > key)		//	Descending
		while(j >= 0 && A[j] > key)		//	Ascending
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}

int partitioning(int* A, int l, int r){
	int p = ((A[(l+r)/2] > A[l] && A[(l+r)/2] < A[r]) || (A[(l+r)/2] < A[l] && A[(l+r)/2] > A[r]))? (l+r)/2 : (((A[(l+r)/2] < A[l] && A[r] > A[l]) || (A[(l+r)/2] > A[l] && A[r] < A[l]))? l : r);
	p = A[p];
	int i = l;
	int j = r;

	while(i < j){

		while(A[i] < p)
		{
			i++;
		}

		while(A[j] > p)
		{
			j--;
		}

		if(i < j)
			swap(A[i], A[j]);
	}
	swap(p, A[j]);
	return j;
}

void quickSort(int* A, int l, int r){
	if(l < r){
		int pivot = partitioning(A, l, r);
		quickSort(A, l, pivot-1);
		quickSort(A, pivot, r);
	}
}

void heapify(int* A, int n, int i){
	int l = 2*i + 1;
	int r = 2*i + 2;
	int max = i;

	if(l < n && A[l] > A[max])
		max = l;

	if(r < n && A[r] > A[max])
		max = r;

	if(max != i){
		swap(A[i], A[max]);
		heapify(A, n, max);
	}

}

void buildHeap(int* A, int n){
	for(int i = n/2 - 1; i >= 0; i--)
		heapify(A, n , i);
}

void heapSort(int* A, int n){
	buildHeap(A, n);

	for(int i = n-1; i >= 0; i--){
		swap(A[0], A[i]);
		heapify(A, i, 0);
	}

}


int main(){
	int A[] = {5, 3, 7, -12, 13, 0, -6, 9, 1, 4, 2};
	int size = sizeof(A) / sizeof(A[0]);
	
	heapSort(A, size);

	for(int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}