#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int x, y;
	int day;
};
queue<Node> q;
int arr[1001][1001];
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int m, n;
int totalDay = 0;

void fun() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int day = q.front().day;
		totalDay = day;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= m || dy >= n) continue;
			if (arr[dx][dy] != 0) continue;
			arr[dx][dy] = 1;
			q.push({ dx,dy,day + 1 });
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				totalDay = -1;
				return;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				q.push({ i,j,0 });
		}
	}
	fun();

	cout << totalDay;
	return 0;
}