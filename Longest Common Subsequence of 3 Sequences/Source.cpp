#include <iostream>
#include <vector>
#include <algorithm>

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

vector<int> lcs2Seq(vector<int> &a, vector<int> &b) {
	
	vector<int> sequence;

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
	int i = a.size(), j = b.size();
	while(i > 0 && j > 0){
		if(matrix[i][j] == matrix[i-1][j-1]+1 && a[i-1] == b[j-1]){
			sequence.push_back(a[i-1]);
			i--;
			j--;
		}else if(matrix[i][j] == matrix[i][j-1])
			j--;
		else
			i--;
	}
	reverse(sequence.begin(), sequence.end());
	cout << matrix[a.size()][b.size()] << endl;
	for(int i = 0; i < sequence.size(); i++)
		cout << sequence[i] << " ";
	cout << endl;
	return sequence;
}


int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
	
	vector<int> lcsAB = lcs2Seq(a, b);
	int lcsABC1 = lcs2(lcsAB, c);

	vector<int> lcsBC = lcs2Seq(b, c);
	int lcsABC2 = lcs2(lcsBC, a);

	return max(lcsABC1, lcsABC2);
}

int main(){

	size_t na;
	cin >> na;
	vector<int> a(na);
	for (size_t i = 0; i < na; i++) {
		cin >> a[i];
	}

	size_t nb;
	cin >> nb;
	vector<int> b(nb);
	for (size_t i = 0; i < nb; i++) {
		cin >> b[i];
	}
	
	size_t nc;
	cin >> nc;
	vector<int> c(nc);
	for (size_t i = 0; i < nc; i++) {
		cin >> c[i];
	}

	cout << lcs3(a, b, c) << endl;

	system("pause");
	return 0;
}
