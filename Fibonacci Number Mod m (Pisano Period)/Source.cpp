#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_faster(long long n, long long m) {
	long long f0 = 0, f1 = 1;
	int i;
	long long pisanoPeriod = 0;
	for (i = 0; i < m*m; i++){
		long long temp = f0;
		f0 = f1;
		f1 = (temp + f1) % m;

		//	A Pisano Period starts with 01
		if (f0 == 0 && f1 == 1)
			break;
	}
	pisanoPeriod = i + 1;
	n = n % pisanoPeriod;
     
    f0 = 0;
	f1 = 1;
    if(n == 0)
        return 0;
    else if( n == 1 )
        return 1;

    for(i = 0; i < n-1; i++){
		long long temp = f0;
        f0 = f1;
		f1 = (temp + f1) % m;
	}    
    return (f1 % m);
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
	std::cout << get_fibonacci_huge_faster(n, m);
	system("pause");
	return 0;
}