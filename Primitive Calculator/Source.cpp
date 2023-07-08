#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> optimal_sequence(int n) {
	vector<int> sequence;
	
	int* nArr = new int [n+1];
	nArr[1] = 0;
	
	for(int i = 2; i <= n; i++){
		
		nArr[i] = nArr[i-1] + 1;
		
		if(i%2 == 0 && (nArr[i/2] + 1) < nArr[i])
			nArr[i] = nArr[i/2] + 1;
		
		if(i%3 == 0 && (nArr[i/3] + 1) < nArr[i])
			nArr[i] = nArr[i/3] + 1;
	}

	int i = n;
	while(i > 1){
		sequence.push_back(i);

		if(nArr[i] == nArr[i-1] + 1)
			i--;
		else if(i%2 == 0 && nArr[i] == nArr[i/2] + 1)
			i /= 2;
		else if(i%3 == 0 && nArr[i] == nArr[i/3] + 1)
			i /= 3;
	}

	sequence.push_back(1);
	reverse(sequence.begin(), sequence.end());

	return sequence;
}


int main() {

	int n;
	cin >> n;
	
	vector<int> sequence = optimal_sequence(n);
	cout << sequence.size() - 1 << std::endl;
	for (size_t i = 0; i < sequence.size(); ++i) {
		cout << sequence[i] << " ";
	}

	system("pause");
	return 0;
}
