#include<iostream>

using namespace std;

//	My Design
int minGroups(double* list, int n){
	double start = list[0];
	int num = 1;

	for(int i = 1; i <= list[n-1]; i++){
		if(list[i] - start > 1){
			num++;
			start = list[i];
		}
	}

	return num;
}

int minGroups_2(double* list, int n){
	int num = 0, i = 0;

	while(i < n){
		double l = list[i], r = list[i] + 1;
		i++;
		num++;
		while(i < n && list[i] <= r)
			i++;
	}

	return num;
}

int main(){

	double list[10];
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> list[i];

	cout << minGroups(list, n) << endl;
	cout << minGroups_2(list, n) << endl;

	system("pause");
	return 0;
}