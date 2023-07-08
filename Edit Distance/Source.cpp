#include <iostream>
#include <string>

using namespace std;

int edit_distance(const string &str1, const string &str2) {

	int a = str1.size();
	int b = str2.size();

	int** matrix = new int* [a+1];
	for(int y = 0; y <= a; y++){
		 matrix[y] = new int [b+1];
		 matrix[y][0] = y;
	}

	for(int x = 0; x <= b; x++)
		matrix[0][x] = x;

  int cal_cost;
  for(int y = 1; y <= a; y++){

	  for(int x = 1; x <= b; x++){
		  cal_cost = (str1[y-1] == str2[x-1]) ? 0 : 1;

		  matrix[y][x] = min(min(matrix[y-1][x], matrix[y][x-1]) + 1, matrix[y-1][x-1] + cal_cost);
	  }
  }

  return matrix[a][b];
}

int main() {
  string str1;
  string str2;
  cin >> str1 >> str2;
  cout << edit_distance(str1, str2) << endl;
  system("pause");
  return 0;
}