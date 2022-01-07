#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

int n, k;
string arr[11];
int used[11];
unordered_map<int, int> number; //메모리 초과 방지
int cnt = 0;

void fun(int lev, string numStr) {
	if (lev == k) {
		int num = stoi(numStr);
		if (number[num] == NULL) {
			number[num] = 1;
			cnt++;
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		fun(lev + 1, numStr + arr[i]);
		used[i] = 0;
	}
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	fun(0, "");

	cout << cnt;

	return 0;
}