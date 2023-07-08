#include<iostream>
#include<cstdlib>		//	We need it to generate some randome numbers
using namespace std;

//	My design		==>>	we get the max 2 numbers through just one loop		==>>	n iterations
long long max_pairwise_product(int* seq, int num){
	long long product = 0;
	int firstMax = seq[0], secondMax = 0;		//	seq[i] might be zero so we take the least possible number for secondMax	==>>	corner case	==	smallest and largest allowed values
	for(int i = 1; i < num; i++){
		if(seq[i] > secondMax){
			secondMax = seq[i];
		}
		if(secondMax > firstMax){
			swap(secondMax, firstMax);
		}
	}
	//	We must cast the result before storing it
	product = (long long)firstMax * secondMax;
	return product;
}

//	Very slow	==>>	we test every 2 numbers	together	==>>	n^2 iterations
//	We can use it in "Stress Test"
long long max_pairwise_product_2(int* seq, int num){
	long long product = 0;
	for(int i = 0; i < num; i++){
		for(int j = i+1; j < num; j++){
			if((long long)seq[i]*seq[j] > product)
				product = (long long)seq[i] * seq[j];
		}
	}
	return product;
}

//	Faster		==>>	we get the max 2 numbers through 2 separated loops		==>>	2*n iterations
long long max_pairwise_product_3(int* seq, int num){
	long long product = 0;
	int maxInd1 = -1;
	for(int i = 0; i < num; i++){
		if(maxInd1 == -1 || seq[i] > seq[maxInd1])
			maxInd1 = i;
	}

	int maxInd2 = -1;
	for(int i = 0; i < num; i++){
		/*
		if(i == maxInd1)
			continue;
		if(( maxInd2 == -1 || seq[i] > seq[maxInd2] ) && seq[maxInd1] >= seq[i])		//	we can replace 3rd condition with ( != ) ==>> seq[maxInd1] is > any seq[i]
			*/																			//	we put >= because the max number might be repeated but we must skip the max number
		if(( maxInd2 == -1 || seq[i] > seq[maxInd2] ) && i != maxInd1)	
			maxInd2 = i;
	}
	product = (long long)seq[maxInd1] * seq[maxInd2];
	return product;
}

void Test(){
	while(true){
		int n = rand() % 1000 + 2;	//	To make n takes value  =< 5
		cout << "n = " << n << endl;
		int seq[1002];
		for(int i = 0; i < n; i++)
			seq[i] = rand() % 100000;
		for(int i = 0; i < n; i++)
			cout << seq[i] << " ";
		cout << endl;

		long long myTest = max_pairwise_product_2(seq, n);
		long long myRes = max_pairwise_product_3(seq, n);

		if(myTest != myRes){
			cout << "!!Wrong Answer!! : " << myTest << " ==>> " << myRes << endl;
			break;
		}else
			cout << "OK\n";
	}
}


int main(){

	//Test();

	
	//cout << "Enter The Number of the sequence: ";
	int num;
	cin >> num;
	int* seq = new int[num];

	//cout << "\nEnter " << num << " space separated positive integers: ";
	for(int i = 0; i < num; i++)
		cin >> seq[i];

	//cout << "\n\nRESULT = " << max_pairwise_product_3(seq, num) << endl;
	cout << max_pairwise_product_3(seq, num);

	delete [] seq;
	
	system("pause");
	return 0;
}