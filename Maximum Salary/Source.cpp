#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

//	My Design
bool isGreater(string a, string b){

	int min = a.size();
	if(b.size() < a.size())
		min = b.size();
	int i;
	for(i = 0; i < min; i++){
		if(a[i] > b[i])
			return true;
		if(a[i] < b[i])
			return false;
	}

	if(b.size() < a.size()){
		for(int j = 0; j < min; j++){
			if(a[i] > b[j])
				return true;
			if(a[i] < b[j])
				return false;
		}
		/*
		if(a[i] > b[0])
			return true;
		return false;
		*/
	}

	if(b.size() > a.size()){
		for(int j = 0; j < min; j++){
			if(b[i] < a[j])
				return true;
			if(b[i] < a[j])
				return false;
		}
		/*
		if(b[i] < a[0])
			return true;
		return false;
		*/
	}
	return false;
}

string largest_number(vector<string> a) {

	std::stringstream ret;
	if(a.size() == 1){
		return a[0];
	}

	while(a.size()){
		string max = a[0];
		int index = 0;
		for (size_t i = 1; i < a.size(); i++)
			if( isGreater(a[i], max) ){
				max = a[i];
				index = i;
			}
		ret << max;
		a.erase(a.begin()+index);
	}

	string result;
	ret >> result;
	return result;
}

bool GreaterOrEqual(string& a, string& b) {
	return(b + a > a + b);
}

string Largeast_Salary(vector<string> Nums, int n) {
	for (size_t i = 1; i < n; i++) {
		for (size_t j = 0; j < n - i; j++) {
			if (GreaterOrEqual(Nums[j], Nums[j + 1])) {
				swap(Nums[j], Nums[j + 1]); 
			}
		}
	}
	std::stringstream Salary; 
	for (size_t i = 0; i < n; i++) {
		Salary << Nums[i]; 
	}
	return Salary.str(); 
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  //std::cout << largest_number(a);
  std::cout << Largeast_Salary(a, a.size());

  system("pause");
  return 0;
}
