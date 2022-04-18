#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int R, C;
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
vector<vector<char>> board;
int used[201];
int maxCnt = 0;

void dfs(int x, int y, int lev) {
	maxCnt = max(maxCnt, lev);

	for (int i = 0; i < 4; i++) {
		int dx = x + direct[i][0];
		int dy = y + direct[i][1];
		if (dx < 0 || dy < 0 || dx >= R || dy >= C) continue;
		char next = board[dx][dy];
		if (used[next] == 1) continue;
		used[next] = 1;
		dfs(dx, dy, lev + 1);
		used[next] = 0;
	}
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		vector<char>line;
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			line.push_back(str[j]);
		}
		board.push_back(line);
	}

	used[board[0][0]] = 1;
	dfs(0, 0, 1);
	cout << maxCnt;

	return 0;
}