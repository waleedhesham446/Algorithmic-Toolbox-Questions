#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;
	int num = weights.size();
	vector<double> valuePerUnitWeight(num);

	for(int i = 0; i < num; i++)
		valuePerUnitWeight[i] = 1.0 * values[i] / weights[i];

	while(capacity > 0){
		int indexOfMax = 0;
		for(int i = 1; i < num; i++)
			if(valuePerUnitWeight[i] > valuePerUnitWeight[indexOfMax] && weights[i] > 0)
				indexOfMax = i;

		int minWeight = weights[indexOfMax];
		if(capacity < minWeight)
			minWeight = capacity;

		if(minWeight == 0)
			return value;

		value += minWeight * valuePerUnitWeight[indexOfMax];
		capacity -= minWeight;
		weights[indexOfMax] -= minWeight;
	}

	return value;
}

int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	system("pause");
	return 0;
}
