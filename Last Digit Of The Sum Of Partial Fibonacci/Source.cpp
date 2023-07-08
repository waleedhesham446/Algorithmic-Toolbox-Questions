#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_faster(long long from, long long to) {
    long long sum = 0;

    int lst_dgt[60] = { 0 };
	lst_dgt[1] = 1;

	for(int i = 2; i < 60; i++)
		lst_dgt[i] = ( lst_dgt[i-1] + lst_dgt[i-2] ) % 10;
	
	if(to%60 < from%60){
		for(int i = 0; i <= to%60; i++)
			sum += lst_dgt[i];
		for(int i = from%60; i <= 59; i++)
			sum += lst_dgt[i];
	}else
		for(int i = from%60; i <= to%60; i++)
			sum += lst_dgt[i];

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
	std::cout << get_fibonacci_partial_sum_faster(from, to);

	system("pause");
	return 0;
}
