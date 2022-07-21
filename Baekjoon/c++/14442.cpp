#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int x, y, lev, cnt;
};
int m, n, k;
int map[1001][1001];
int used[1001][1001][11]; // used[x][y][���� �μ� ���� �ִ°�]
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int Min = 0;


int bfs() {
	queue<Node> q;
	q.push({ 0,0,1,0 });
	used[0][0][0] = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int lev = q.front().lev; //�� ĭ ����
		int cnt = q.front().cnt; //���� �μ� Ƚ��
		q.pop();

		if (x == m - 1 && y == n - 1)
			return lev;

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			int wall = 0; //���� �վ����� flag
			if (dx < 0 || dy < 0 || dx >= m || dy >= n) continue;
			if (map[dx][dy] == 1) {
				if (cnt >= k) continue;
				wall = 1;
			}
			//���� �ν��ٸ�  : used[dx][dy][cnt] = 1
			//���� �Ⱥν��ٸ�: used[dx][dy][cnt+1] = 1
			//used �迭 : ���� ���� �� ���� ������ �湮�� ���� �ִ°��� Ȯ��
			//���� ���� �μ� Ƚ��+1�� Ƚ���� �̵��Ϸ��� ���� �湮�� ���� �ִ°�
			if (used[dx][dy][cnt + wall] == 1) continue;
			used[dx][dy][cnt + wall] = 1;
			q.push({ dx,dy,lev + 1, cnt + cnt });
		}
	}
	return -1;
}


int main() {
	cin >> m >> n >> k;
	for (int i = 0; i < m; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < n; j++)
			map[i][j] = line[j] - '0';
	}
	cout << bfs();
	return 0;
}