#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[100001];
vector<int> result;

void fun(int num) {
	int start = 0;
	int end = n - 1;

	while (1) {
		if (start > end) {
			result.push_back(0);
			return;
		}

		int mid = (start + end) / 2;
		if (arr[mid] < num) {
			start = mid + 1;
		}
		else if (arr[mid] > num) {
			end = mid - 1;
		}
		else if (arr[mid] == num) {
			result.push_back(1);
			return;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		fun(num);
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

	return 0;
}