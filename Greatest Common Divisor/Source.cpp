#include<iostream>

using namespace std;
//	For array of integers
void GCD(int* arr, int n){
	int gcd = 1;
	int min = arr[0];
	for(int i = 1; i < n; i++)
		if(arr[i] < min)
			min = arr[i];
	for(int i = 2; i <= min; i++){
		int j;
		for(j = 0; j < n; j++)
			if(arr[j] % i != 0)
				break;
		if(j = n)
			gcd = i;
	}
	
	cout << "GCD: " << gcd << endl;
}
//	My Design
int GCD(int a, int b){
	int gcd = 1;
	int min = a;
	if(b < a)
		min = b;
	
	for(int i = 2; i <= min; i++){
		if(a%i == 0 && b%i == 0)
			gcd = i;
	}

	return gcd;
}

/*
bool isPrime(int n){
	int i;
	if(n == 2)
		return true;
	for(i = 2; i < n; i++)
		if(n % i == 0)
			break;
	if(i == n)
		return true;
	return false;
}

int* primeFactors(int n, int &counter){
	int primeFact[100] = {0};
	counter = 0;
	for(int i = 2; i <= n; i++){
		if(isPrime(i)){
			int temp = n % i;
			while(temp == 0){
				primeFact[counter++] = i;
				temp %= i;
			}
		}
	}
	return primeFact;
}

int GCD_2(int a, int b){
	int aCount;
	int* aPrimFact = primeFactors(a, aCount);

	int bCount;
	int* bPrimFact = primeFactors(b, bCount);
	
	int gcd = 1;
	
	int max = bCount;
	if(aCount > bCount)
		max = aCount;
	
	for(int i = 0; i <= max; i++)
		if(aPrimFact[i] == bPrimFact[i])
			gcd *= aPrimFact[i];

	return gcd;
}
*/

//	Basic Euclidean Algorithm
long long Euclidean_GCD(long long a, long long b){
	if(b == 0)
		return a;
	return Euclidean_GCD(b, a%b);
}	//	Time complexity = O(Log min(a, b))

//	Extended Euclidean Algorithm
int Extended_GCD(int a, int b, int *x, int *y){
	// Base Case
	if(b == 0){
		*x = 1;
		*y = 0;
		return a;
	}

	int x1, y1; // To store results of recursive call
	int gcd = Extended_GCD(b, a%b, &x1, &y1);

	// Update x and y using results of recursive call
    *x = y1;				//	new_x	==>>	prev_y
    *y = x1 - (a/b) * y1;	//	new_y	==>>	prev_x - Q * new_x(prev_y)

	return gcd;
}

int main(){
	/*
	cout << "Enter the two numbers: ";
	int a, b;
	cin >> a >> b;
	
	int x = 0, y = 0;
	int res = Extended_GCD(a, b, &x, &y);
	cout << x << " x " << a << " + " << y << " x " << b << " = " << res << endl;
	*/
	long long a, b;
	cin >> a >> b;
	cout << Euclidean_GCD(a, b);

	system("pause");
	return 0;
}