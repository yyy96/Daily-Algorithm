#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Node {
	int now;
	int lev;
};
int n;
int a, b;
int m;
vector<vector<int>> v(100);
int used[100];

int bfs() {
	queue<Node> q;
	q.push({ a, 0 });

	while (!q.empty()) {
		int now = q.front().now;
		int lev = q.front().lev;
		q.pop();

		if (now == b)
			return lev;

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (used[next] == 1) continue;
			used[next] = 1;
			q.push({ next, lev + 1 });
		}
	}
	return -1;
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

	cout << bfs();

	return 0;
}