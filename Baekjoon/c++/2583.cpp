#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
	int x, y;
};
int m, n, k;
int arr[101][101] = { 0, };
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
vector<int> square;

//BFS Ç®ÀÌ
void bfs(int x, int y) {
	int used[100][100] = { 0, };
	queue<Node> q;
	q.push({ x,y });
	used[x][y] = 1;
	int size = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= m || dy >= n) continue;
			if (used[dx][dy] == 1) continue;
			if (arr[dx][dy] == 2) continue;
			used[dx][dy] = 1;
			arr[dx][dy] = 1;
			q.push({ dx,dy });
			size++;
		}
	}

	square.push_back(size);
}

void paint(int sx, int sy, int ex, int ey) {
	for (int i = sx; i <= ex; i++) {
		for (int j = sy; j <= ey; j++)
			arr[i][j] = 2;
	}
}

int main() {
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {
		int sx, sy, ex, ey;
		cin >> sy >> sx >> ey >> ex;
		paint(sx, sy, ex-1, ey-1);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 0) continue;
			bfs(i, j);
		}
	}

	int squareCnt = square.size();
	cout << squareCnt << endl;
	sort(square.begin(), square.end());
	for (int i = 0; i < squareCnt; i++) {
		cout << square[i] << " ";
	}

	return 0;
}