#include<iostream>

using namespace std;

int maxValue(int* values, int* weight, int n, int capacity){
	int* valuePerUnit = new int[n];

	for(int i = 0; i < n; i++)
		valuePerUnit[i] = values[i] / weight[i];

	int v = 0;
	for(int i = 0; i < n; i++){
		if(capacity == 0)
			return v;

		//	Getting The Index Of Item With Max Value Per Unit Weight
		int indexOfMax = 0;
		for(int i = 1; i < n; i++)
			if(valuePerUnit[i] > valuePerUnit[indexOfMax] && weight[i] > 0)
				indexOfMax = i;

		//	Getting The Min Weight ( The Item || The Rest Of The Capacity )
		int minWeight = weight[indexOfMax];
		if(capacity < minWeight)
			minWeight = capacity;

		v += valuePerUnit[indexOfMax] * minWeight;
		capacity -= minWeight;
		weight[indexOfMax] -= minWeight;

	}

	delete [] valuePerUnit;

	return v;
}	//	O(n^2)		==>>	We could make it n*log(n) if we sorted the array "valuePerUnit" before the main loop


int main(){

	int capacity;
	int n;
	cin >> capacity;
	cin >> n;
	int* values = new int[n];
	int* weights = new int[n];
	for(int i = 0; i < n; i++)
		cin >> values[i];
	for(int i = 0; i < n; i++)
		cin >> weights[i];

	cout << maxValue(values, weights, n, capacity) << endl;

	delete []values;
	delete []weights;

	system("pause");
	return 0;
}