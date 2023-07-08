#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

//	My Design
long long lcm_faster(int a, int b) {
	int max = a;
	if(b > a)
		max = b;
	
	for (long l = max; l <= (long long) a * b; l += max)
	if (l % a == 0 && l % b == 0)
		return l;

	return (long long) a * b;
}

//	 Formula for LCM using GCD:			a x b = LCM(a, b) * GCD (a, b)
int Euclidean_GCD(int a, int b){
	if(b == 0)
		return a;
	return Euclidean_GCD(b, a%b);
}

long long lcm_faster_2(int a, int b){
	return (long long) a / Euclidean_GCD(a, b) * b;		//	we must divid a first
}



int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_faster_2(a, b) << std::endl;
  system("pause");
  return 0;
}
