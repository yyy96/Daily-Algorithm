#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring> //memcpy
using namespace std;
//최대 크기이니까 dfs

struct Node {
	int x, y;
};
int n, m;
int arr[9][9];
int maxArea = 0;
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

void virusArea() {
	int result[9][9];
	queue<Node> virus;
	int safeArea = 0;
	memcpy(result, arr, sizeof(arr));

	//큐 init
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2)
				virus.push({ i,j });
		}
	}

	//bfs 바이러스 퍼지기
	while (!virus.empty()) {
		int x = virus.front().x;
		int y = virus.front().y;
		virus.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
			if (result[dx][dy] != 0) continue;
			result[dx][dy] = 2;
			virus.push({ dx,dy });
		}
	}

	//0인 지역 check
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (result[i][j] == 0)
				safeArea++;
		}
	}

	if (safeArea > maxArea)
		maxArea = safeArea;
}

void dfs(int lev) {
	if (lev == 3) {
		virusArea();
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 0) continue;
			arr[i][j] = 1;
			dfs(lev + 1);
			arr[i][j] = 0;
		}
	}
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	dfs(0);
	cout << maxArea;

	return 0;
}
