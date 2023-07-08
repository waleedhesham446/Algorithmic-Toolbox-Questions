#include<iostream>
#include<vector>

using namespace std;

//	My design
long long f(int num){
	long long f0 = 0, f1 = 1, f = 1;	//	Line 1 & 2 & 3
	
	if(num == 0)						//	Line 4
		return 0;

	for(int i = 2; i <= num; i++){		//	iterates over 4*(n-1) line of code
		f = f0 + f1;
		f0 = f1;
		f1 = f;
	}
	return f;							//	Line 5
}	//	T(n) = 4*n + 1			, for n > 1
	//	T(n) = 5				, for n <= 1
	//	But, This takes memory less than f_2()

long long f_2(int num){
	vector<long long> f(num+1);			//	line 1
	f[0] = 0;							//	line 2
	f[1] = 1;							//	line 3
	for(int i = 2; i <= num; i++)		//	iterates over 2*(n-1) line of code
		f[i] = f[i-1] + f[i-2];
	return f[num];						//	line 4
}	//	T(n) = 2*n + 2			, for any n
/*
//	Using Formela
long double f_3(int num){
	
	return ( (long double)1/sqrt(5) ) * ( pow( ( 1+sqrt(5) ) / 2, num) - pow( ( 1-sqrt(5) ) / 2, num));
}
*/
//	Recursive solution	==>>	not efficient	==>>	The greater num is, the more repeated f(i) is calculated	==>> repeat as a tree
long long f_recurs(int num){
	
	if(num <= 1){
		return num;
	}

	return (f_recurs(num-1) + f_recurs(num-2));
}

int main(){

	//cout << "Enter the number: ";
	int num;
	cin >> num;

	//cout << endl << "F" << num << " ==>> " << f_2(num) << endl;
	cout << f_2(num);
	
	system("pause");
	return 0;
}