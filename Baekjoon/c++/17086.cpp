#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 51
using namespace std;

struct Node {
	int x, y, lev;
};
int n, m;
int result = 0;
int map[MAX][MAX];
int dist[MAX][MAX] = { 0, };
int direct[8][2] = { {-1,0},{1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,1},{1,-1} };
vector<Node> shark;

void bfs(Node bbshark) {
	bool visited[MAX][MAX] = { false };
	queue<Node> q;
	q.push(bbshark);

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int lev = q.front().lev;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
			if (map[dx][dy] == 1) continue; //아기 상어이면 볼 필요x
			if (visited[dx][dy]) continue;
			if (lev + 1 > dist[dx][dy] && dist[dx][dy] != 0) continue; //이미 나보다 짧다면 볼 필요x
			visited[dx][dy] = true;
			dist[dx][dy] = lev + 1;
			q.push({ dx,dy,lev + 1 });
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) shark.push_back({ i,j,0 });
		}
	}

	for (Node s : shark)
		bfs(s);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			result = max(result, dist[i][j]);
	}
	cout << result;
}