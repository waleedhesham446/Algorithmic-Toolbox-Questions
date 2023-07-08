// #include <iostream>
// #include <cmath>
// #include <string>
// #include <string.h>
// #include <stdlib.h>
// #include <algorithm>
// #include <iomanip>
// #include <assert.h>
// #include <vector>
// #include <cstring>
// #include <map>
// #include <deque>
// #include <queue>
// #include <stack>
// #include <sstream>
// #include <cstdio>
// #include <cstdlib>
// #include <ctime>
// #include <set>
// #include <complex>
// #include <list>
// #include <climits>
// #include <cctype>
// #include <bitset>
// #include <numeric>
// #include <array>
// #include <tuple>
// #include <stdexcept>
// #include <utility>
// #include <functional>
// #include <locale>

// using std::vector;

// int get_majority_element(vector<int> &a, int left, int right) {
// 	//if (left == right) return -1;
// 	//if (left + 1 == right) return a[left];
// 	//write your code here
	
// 	if (left == right)
// 		return a[left];
// 	int mid = (left + right-1) / 2;
// 	int leftPart = get_majority_element(a, left, mid);
// 	int righttPart = get_majority_element(a, mid+1,right);

// 	if (leftPart == -1 && righttPart == -1) 
// 		return -1;
// 	else if (leftPart == -1 && righttPart != -1) 
// 		return righttPart;
// 	else if (leftPart != -1 && righttPart == -1) 
// 		return leftPart;
// 	else if (leftPart != righttPart) 
// 		return -1;
// 	else return leftPart;
// }

// bool ContainMajority(vector<int> Arr, int n) {
// 	map<int, int> Freq; 
// 	for (size_t i = 0; i < n; i++)
// 		Freq[Arr[i]]++;

// 	for (int i = 0; i <n; i++)
// 		if (Freq[Arr[i]] > (n / 2))
// 			return true; 
	
// 	return false;
// }

// int main() {
//   int n;
//   std::cin >> n;
//   vector<int> a(n);
//   for (size_t i = 0; i < a.size(); ++i) {
//     std::cin >> a[i];
//   }
// //   std::cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
//   std::cout << ContainMajority(a, n) << '\n';

//   system("pause");
//   return 0;
// }


// #include <iostream>
// #include <cmath>
// #include <algorithm>
// #include <vector>
// typedef   long long int               ll;

// //freopen("input.txt","r",stdin);
// //freopen("output.txt","w",stdout);

// using namespace std;
// pair<int, int> partition3(vector<int> &a, int l, int r) {
// 	int x = a[l], m1;
// 	int j = l;
// 	for (int i = l + 1; i <= r; i++) {
// 		if (a[i] <= x) {
// 			j++;
// 			swap(a[i], a[j]);
// 		}
// 	}
// 	swap(a[l], a[j]);
// 	m1 = j - 1;
// 	for (int i = l; i < j && m1 >= l && m1 > i;)
// 	{
// 		if (a[j] == a[i])
// 			swap(a[i], a[m1--]);
// 		else
// 			i++;
// 	}
// 	m1++;
// 	return make_pair(m1, j);
// }

// void randomized_quick_sort(vector<int> &a, int l, int r) {
// 	if (l >= r) {
// 		return;
// 	}

// 	int k = l + rand() % (r - l + 1);
// 	swap(a[l], a[k]);
// 	pair<int, int> m = partition3(a, l, r);

// 	randomized_quick_sort(a, l, m.first - 1);
// 	randomized_quick_sort(a, m.second + 1, r);
// }

// int main() {
// 	int n;
// 	cin >> n;
// 	vector<int> a(n);
// 	for (size_t i = 0; i < a.size(); ++i) {
// 		cin >> a[i];
// 	}
// 	randomized_quick_sort(a, 0, a.size() - 1);
// 	for (size_t i = 0; i < a.size(); ++i) {
// 		cout << a[i] << ' ';
// 	}
// }

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
typedef   long long int               ll;

using namespace std;
  
int MERGESORT(int arr[], int temp[], int left, int right); 
int merge(int arr[], int temp[], int left, int mid, int right); 

int mergeSort(int arr[], int array_size) { 
    int temp[array_size]; 
    return MERGESORT(arr, temp, 0, array_size - 1); 
} 

int MERGESORT(int arr[], int temp[], int left, int right) { 
    int mid, inv_count = 0; 
    if (right > left) { 
        mid = (right + left) / 2; 
        inv_count = MERGESORT(arr, temp, left, mid); 
        inv_count += MERGESORT(arr, temp, mid + 1, right); 
  
        inv_count += merge(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
} 

int merge(int arr[], int temp[], int left, int mid, int right) { 
    int i, j, k; 
    int inv_count = 0; 
  
    i = left; 
    j = mid; 
    k = left;
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
  
            inv_count = inv_count + (mid - i); 
        } 
    } 
  
  
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
  
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 
int main(){
    int n ; 
    scanf("%d",&n);
    int arr[n];
    for(int i=0 ;i<n ;i++)
        scanf("%d",&arr[i]);
    cout << mergeSort(arr,n) << endl ;
}
