#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<int> &w) {

	vector<vector<int>> matrix(w.size()+1, vector<int>(W+1, 0));

	for(int i = 1; i <= w.size(); i++){
		for(int j = 1; j <= W; j++){
			matrix[i][j] = matrix[i-1][j];
			if(j >= w[i-1]){
				int val = matrix[i-1][j-w[i-1]] + w[i-1];
				matrix[i][j] = max(matrix[i][j], val);
			}
		}
	}
	return matrix[w.size()][W];
}

int main() {
	int n, W;
	cin >> W >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	cout << optimal_weight(W, w) << '\n';

	system("pause");
	return 0;
}
