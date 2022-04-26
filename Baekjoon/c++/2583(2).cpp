#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int m, n, k;
int arr[101][101] = { 0, };
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
vector<int> square;
int squareSize = 0;

//DFS 풀이
void dfs(int x, int y) {
	//이 조건이 없으면 그냥 현재 arr[x][y]=1 이어도 다시 size 를 체크해준다.
	if (arr[x][y] != 0) {
		return;
	}
	arr[x][y] = 1;
	squareSize++;

	for (int i = 0; i < 4; i++) {
		int dx = x + direct[i][0];
		int dy = y + direct[i][1];
		if (arr[dx][dy] == 1) continue;
		if (dx < 0 || dy < 0 || dx >= m || dy >= n) continue;
		dfs(dx, dy);
	}
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
		paint(sx, sy, ex - 1, ey - 1);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 0) continue;
			dfs(i, j);
			square.push_back(squareSize);
			squareSize = 0;
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