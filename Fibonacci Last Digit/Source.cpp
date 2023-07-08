#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {			//	# of iterations = n-2
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

//	The same approach
int get_fibonacci_last_digit_faster(int n) {	//	# of iterations = n-2
	
	if(!n)
		return 0;

	long long f0 = 0;
	long long f1 = 1;
	long long fib = 1;

	for (int i = 2; i <= n; ++i) {
		fib = f1 + f0;
		f0 = f1;
		f1 = fib;
	}

	return fib % 10;
}	//	Not working for big n = (200)

//	Here we just store the last digit of Fibonacci Sequence according to this formula:
//	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, ...
//	0, 1, 1, 2, 3, 5, 8,  3,  1,  4,  5,  9,   4,   3,   7,   0,   7, ...
int get_fibonacci_last_digit_faster_2(int n) {
	
	if(!n)
		return 0;

	int f0_lst_dgt = 0;
	int f1_lst_dgt = 1;
	int fib_lst_dgt = 1;

	for (int i = 2; i <= n; ++i) {
		fib_lst_dgt = (f1_lst_dgt + f0_lst_dgt) % 10;
		f0_lst_dgt = f1_lst_dgt;
		f1_lst_dgt = fib_lst_dgt;
	}

	return fib_lst_dgt;
}	//	But there is a more fast trick...

//	0, 1, 1, 2, 3, 5, 8,  3,  1,  4,  5,  9,   4,   3,   7,   0,   7, ...		==>>	This series is just 60 ( fib(0) -> fib(59) ) numbers long and then it repeats the same sequence again
int get_fibonacci_last_digit_faster_3(long long n) {
	
	int fib_lst_dgt[60];
	fib_lst_dgt[0] = 0;
	fib_lst_dgt[1] = 1;

	for (int i = 2; i < 60; i++) {
		fib_lst_dgt[i] = (fib_lst_dgt[i-1] + fib_lst_dgt[i-2]) % 10;
	}

	return fib_lst_dgt[n % 60];
}	//	Complexity: O(1)

int main() {
    long long n, m;
    std::cin >> n;
    int c = get_fibonacci_last_digit_faster_3(n);
    std::cout << c;

	system("pause");
	return 0;
}
