#include<iostream>

using namespace std;

void polynomial_multiplication_naive(int* a, int* b, int n){
	int* result = new int [2*n - 1];
	for(int i = 0; i < 2*n-1; i++)
		result[i] = 0;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			result[i+j] += (a[i] * b[j]);

	for(int i = 0; i < 2*n-1; i++)
		cout << result[i] << " ";
	cout << endl;
	delete [] result;
}	//	O(n2)

int* polynomial_multiplication_naive_2(int* a, int* b, int n, int al, int bl){
	int* result = new int [2*n - 1];
	if(n == 1){
		result[0] = a[al] * b[bl];
		return result;
	}

	for(int i = 0; i < 2*n-1; i++)
		result[i] = 0;

	

	for(int i = 0; i < 2*n-1; i++)
		cout << result[i] << " ";
	cout << endl;
	delete [] result;
}	//	T(n) = 4*T(n/2) + k*n		//	we divide our problem into 4 subproblems of size n/2
	//	Theta(n2)

int main(){
	int a[3] = {3, 4, 8};
	int b[3] = {5, 6, 2};

	polynomial_multiplication_naive(a, b, 3);
	

	system("pause");
	return 0;
}
