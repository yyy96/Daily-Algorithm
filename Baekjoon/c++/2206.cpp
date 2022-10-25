#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

struct Node {
	int x, y;
	int lev;
	bool crush;
};
int n, m;
vector<vector<int>> map(MAX);
bool visited[MAX][MAX][2] = { false, };
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

int bfs() {
	queue<Node> q;
	q.push({ 0,0,1,false });
	visited[0][0][false] = true;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		if (now.x == n - 1 && now.y == m - 1)
			return now.lev;

		for (int i = 0; i < 4; i++) {
			int dx = now.x + direct[i][0];
			int dy = now.y + direct[i][1];
			bool crush = now.crush;
			if (dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
			if (map[dx][dy] == 1) {
				if (now.crush) continue;
				crush = true;
			}
			if (visited[dx][dy][crush]) continue;
			visited[dx][dy][crush] = true;
			q.push({ dx,dy, now.lev + 1, crush });
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < m; j++)
			map[i].push_back(str[j] - '0');
	}
	cout << bfs();
	return 0;
}