#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[9];
int path[9];
int used[9];
int maxSum = 0;

void cal() {
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		int num = abs(path[i] - path[i + 1]);
		sum += num;
	}
	maxSum = max(maxSum, sum);
}

void dfs(int lev) {
	if (lev == n) {
		cal();
		return;
	}

	for (int i = 0; i < n; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path[lev] = arr[i];
		dfs(lev + 1);
		path[lev] = 0;
		used[i] = 0;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	dfs(0);
	cout << maxSum;
	return 0;
}
