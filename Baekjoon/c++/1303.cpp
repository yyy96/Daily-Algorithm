#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int x, y;
};
int n, m;
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
vector<vector<char>> map;
int W, B;

void bfs(int sx, int sy, char team) {
	queue<Node> q;
	q.push({ sx,sy });
	int cnt = 1;
	map[sx][sy] = '-';

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
			if (map[dx][dy] != team) continue;
			map[dx][dy] = '-';
			q.push({ dx,dy });
			cnt += 1;
		}
	}

	if (team == 'W') W += cnt * cnt;
	if (team == 'B') B += cnt * cnt;
}

int main()
{
	cin >> m >> n; //가로세로 주의

	for (int i = 0; i < n; i++) {
		vector<char> line;
		string s; cin >> s;
		for (int j = 0; j < m; j++)
			line.push_back(s[j]);
		map.push_back(line);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '-') continue;
			bfs(i, j, map[i][j]);
		}
	}

	cout << W << " " << B;
	return 0;
}