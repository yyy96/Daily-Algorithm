#include <string>
#include <vector>
#include <iostream>
using namespace std;

int n;
int a, b;
int m;
vector<vector<int>> v(100);
int used[100];
int result = -1;

void dfs(int lev, int now) {
	if (now == b) {
		result = lev;
		return;
	}

	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (used[next] == 1) continue;
		used[next] = 1;
		dfs(lev + 1, next);
		used[next] = 0;
	}
}

int main() {
	cin >> n;
	cin >> a >> b;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(0, a);
	cout << result;

	return 0;
}