#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return int(n);

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

//	My Design
int fibonacci_sum_faster(long long n) {

	long long sum = 0;

	int lst_dgt[60] = { 0 };
	lst_dgt[1] = 1;

	for(int i = 2; i < 60; i++)
		lst_dgt[i] = ( lst_dgt[i-1] + lst_dgt[i-2] ) % 10;
	
	for(int i = 0; i <= n%60; i++){
		sum += lst_dgt[i];
	}

	return sum % 10;
}

int main() {
	
	long long n = 0;
	std::cin >> n;
	std::cout << fibonacci_sum_faster(n);
	//std::cout << fibonacci_sum_naive(n) << std::endl;
	
	system("pause");
	return 0;
}
