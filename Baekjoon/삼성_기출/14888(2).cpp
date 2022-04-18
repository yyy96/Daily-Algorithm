#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int n;
vector<int> num;
vector<int> math;
int maxResult = -21e8;
int minResult = 21e8;


void dfs(int lev, int sum) {
	if (lev == num.size() - 1) {
		maxResult = max(maxResult, sum);
		minResult = min(minResult, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (math[i] == 0) continue;
		math[i]--;
		if (i == 0) dfs(lev + 1, sum + num[lev + 1]);
		else if (i == 1) dfs(lev + 1, sum - num[lev + 1]);
		else if (i == 2) dfs(lev + 1, sum * num[lev + 1]);
		else if (i == 3) dfs(lev + 1, sum / num[lev + 1]);
		math[i]++;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		num.push_back(number);
	}

	for (int i = 0; i < 4; i++) {
		int m;
		cin >> m;
		math.push_back(m);
	}

	dfs(0, num[0]);
	cout << maxResult << endl;
	cout << minResult << endl;

	return 0;
}