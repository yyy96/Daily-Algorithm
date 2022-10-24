#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 51
using namespace std;

int map[MAX][MAX];
int visited[MAX][MAX];
int direct[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int r, c, d;
int n, m;

void dfs(int x, int y, int d, int sum) {
	for (int i = 0; i < 4; i++) {
		int dx = x + direct[i][0];
		int dy = y + direct[i][1];
		int newd = (d + 3 - i) % 4;

		if (dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
		if (map[dx][dy] == 1) continue;
		if (visited[dx][dy] == 0 && map[dx][dy] == 0) {
			visited[dx][dy] = 1;
			dfs(dx, dy, newd, sum + 1);
		}
	}

	int back = d + 2 < 4 ? d + 2 : d - 2;
	int dx = x + direct[back][0];
	int dy = y + direct[back][1];
	if (dx < 0 || dy < 0 || dx >= n || dy >= m) return;
	if (map[dx][dy] == 0) dfs(dx, dy, d, sum);
	else {
		cout << sum;
		exit(0);
	}
}

int main()
{
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	visited[r][c] = 1;
	dfs(r, c, d, 1);
	return 0;
}
