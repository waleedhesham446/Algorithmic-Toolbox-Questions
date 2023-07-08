#include <iostream>

using namespace std;

int minNumCoins(int money) {

	int* minCoins = new int [money+1];
	int coins[3] = {1, 3, 4};

	minCoins[0] = 0;
	for(int i = 1; i <= money; i++){
		minCoins[i] = i;
		for(int j = 0; j < 3; j++){
			if(i >= coins[j]){
				int numCoins = minCoins[i - coins[j]] + 1;
				if(numCoins < minCoins[i])
					minCoins[i] = numCoins;
			}
		}
	}

	return minCoins[money];
}


int main() {

	int money = 0;
	cin >> money;

	int minCoins = minNumCoins(money);

	cout << minCoins << endl;

	system("pause");
	return 0;
}
