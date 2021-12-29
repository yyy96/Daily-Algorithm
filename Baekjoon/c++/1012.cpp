#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int x, y;
};
int T;
int m, n, k;
int arr[25][25] = { 0, };
int used[25][25] = { 0, };
int direct[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
queue<Node> q;

void fun() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= m || dy >= n) continue;
			if (arr[dx][dy] == 0) continue;
			if (used[dx][dy] == 1) continue;
			used[dx][dy] = 1;
			q.push({ dx,dy });
		}
	}
}

int main() {

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> m >> n >> k;
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (used[i][j] == 1) continue;
				if (arr[i][j] == 1) {
					cnt++;
					q.push({ i,j });
					used[i][j] = 1;
					fun();
				}
			}
		}
		for (int i = 0; i < m; i++) {
			memset(arr[i], 0, sizeof(arr[i]));
			memset(used[i], 0, sizeof(used[i]));
		}
		cout << cnt <<endl;
	}
	return 0;
}