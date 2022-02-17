#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
int arr[11][11];
int used[11];
int Min = 2e8;

void dfs(int lev, int now, int start, int sum) {
	if (sum > Min) return;
	if (lev == n) {
		if (arr[now][start] > 0)
			Min = min(sum + arr[now][start], Min);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (arr[now][i] == 0) continue;
		if (used[i] == 1) continue;
		used[i] = 1;
		dfs(lev + 1, i, start, sum + arr[now][i]);
		used[i] = 0;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	for (int start = 0; start < n; start++) {
		used[start] = 1;
		dfs(1, start, start, 0);
		used[start] = 0;
	}
	cout << Min;
	return 0;
}