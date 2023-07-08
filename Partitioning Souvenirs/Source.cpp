#include <iostream>
#include <vector>

using namespace std;

int partition3(vector<int> &A) {
	
	int sum = 0;
	for(int i = 0; i < A.size(); i++)
		sum += A[i];
	if(sum % 3)
		return 0;
	else
		sum /= 3;

	vector<vector<int>> matrix(sum+1, vector<int>(A.size()+1, 0));
	
	for(int i = 1; i <= sum; i++){
		for(int j = 1; j <= A.size(); j++){
			matrix[i][j] = matrix[i][j-1];
			if(A[j-1] == i)
				matrix[i][j] = matrix[i][j-1] + 1;
			else if(i-A[j-1] >= 0 && matrix[i-A[j-1]][j-1] > 0)
				matrix[i][j] = matrix[i][j-1] + 1;
		}
	}
	
	return (matrix[sum][A.size()] >= 2)? 1 : 0;
}

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (size_t i = 0; i < A.size(); ++i) {
		cin >> A[i];
	}
	cout << partition3(A) << '\n';
	
	system("pause");
	return 0;
}
