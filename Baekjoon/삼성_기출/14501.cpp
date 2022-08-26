#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Work {
	int T, P;
};
int n;
vector<Work> schedule;
int result = 0;

void dfs(int day, int sum) {
	if (day > n) return;
	result = max(result, sum);

	for (int i = day; i < n; i++) {
		dfs(i + schedule[i].T, sum + schedule[i].P);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t, p;
		cin >> t >> p;
		schedule.push_back({ t,p });
	}
	dfs(0, 0);
	cout << result;
	return 0;
}