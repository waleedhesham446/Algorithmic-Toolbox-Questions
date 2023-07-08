#include <iostream>
#include <vector>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
	
	int** matrix = new int* [a.size()+1];
	for(int y = 0; y <= a.size(); y++){
		matrix[y] = new int [b.size()+1];
		 matrix[y][0] = 0;
	}

	for(int x = 0; x <= b.size(); x++)
		matrix[0][x] = 0;
	
	for(int y = 1; y <= a.size(); y++){
		for(int x = 1; x <= b.size(); x++){
			if(a[y-1] == b[x-1])
				matrix[y][x] = matrix[y-1][x-1] + 1;
			else
				matrix[y][x] = max(matrix[y-1][x], matrix[y][x-1]);
		}
	}
	return matrix[a.size()][b.size()];
}

int main() {
	size_t n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++) {
		cin >> a[i];
	}

	size_t m;
	cin >> m;
	vector<int> b(m);
	for (size_t i = 0; i < m; i++) {
		cin >> b[i];
	}

	cout << lcs2(a, b) << std::endl;

	system("pause");
	return 0;
}
