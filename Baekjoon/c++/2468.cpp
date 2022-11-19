#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

struct Node {
	int x, y;
};
int n;
int minH = MAX, maxH = 0;
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int result = 0;

void bfs(int x, int y, int h, vector<vector<int>> &map) {
	queue<Node> q;
	q.push({ x,y });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
			if (map[dx][dy] < h) continue;
			map[dx][dy] = -1;
			q.push({ dx,dy });
		}
	}
}

int solution(int h, vector<vector<int>> map) {
	int area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] < h) continue;
			//안전지대 개수 구하기
			bfs(i, j, h, map);
			area++;
		}
	}
	return area;
}

int main() {
	vector<vector<int>> map(MAX);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int h; cin >> h;
			map[i].push_back(h);
			minH = min(minH, h);
			maxH = max(maxH, h);
		}
	}

	for (int h = minH; h <= maxH; h++) {
		result = max(result, solution(h, map));
	}
	cout << result;
	return 0;
}