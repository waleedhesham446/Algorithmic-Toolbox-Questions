#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>

using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {

	int length = exp.size();
	int numOfnum = (length + 1) / 2;

	vector<vector<long long>> m(numOfnum, vector<long long>(numOfnum, 0));
	vector<vector<long long>> M(numOfnum, vector<long long>(numOfnum, 0));
	
	int numIndex = 0;
	for(int i = 0; i < numOfnum; i++){
		m[i][i] = exp[numIndex]-48;
		M[i][i] = exp[numIndex]-48;
		numIndex += 2;
	}

	for(int s = 0; s < numOfnum-1; s++){
		for(int i = 0; i < numOfnum-s; i++){
			int j = i + s;
			long long minVal = pow(9, 14);
			long long maxVal = 0-pow(9, 14);
			for(int k = i; k < j-1; k++){
				long long a = eval(M[i][k], M[k+1][j], exp[2*k +  1]);
				long long b = eval(M[i][k], m[k+1][j], exp[2*k +  1]);
				long long c = eval(m[i][k], M[k+1][j], exp[2*k +  1]);
				long long d = eval(m[i][k], m[k+1][j], exp[2*k +  1]);

				minVal = min(minVal,min(a,min(b,min(c,d))));
				maxVal = max(maxVal,max(a,max(b,max(c,d))));
			}
			m[i][j] = minVal;
			M[i][j] = maxVal;
		}

	}

	for(int i = 0; i < numOfnum; i++){
		for(int j = 0; j < numOfnum; j++)
			cout << m[i][j] << "  ";
		cout << endl;
	}
	cout << endl << "########################" << endl << endl;
	for(int i = 0; i < numOfnum; i++){
		for(int j = 0; j < numOfnum; j++)
			cout << M[i][j] << "    ";
		cout << endl;
	}
	cout << endl;
	return M[0][numOfnum-1];
}

int main() {
  string s;
  cin >> s;
  cout << get_maximum_value(s) << '\n';

  system("pause");
  return 0;
}
