#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

struct Node {
	int x, y;
};
char map[12][6];
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int result = 0;

bool check(int sx, int sy, char color) {
	int used[12][6] = { 0, };
	int cnt = 0;
	queue<Node> q;
	q.push({ sx,sy });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		if (cnt >= 4) return true;

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= 12 || dy >= 6) continue;
			if (map[dx][dy] != color) continue;
			if (used[dx][dy] == 1) continue;
			used[dx][dy] = 1;
			cnt++;
			q.push({ dx,dy });
		}
	}
	return false;
}

void puyo(int sx, int sy, char color) {
	queue<Node> q;
	q.push({ sx,sy });
	map[sx][sy] = '.';

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= 12 || dy >= 6) continue;
			if (map[dx][dy] != color) continue;
			map[dx][dy] = '.';
			q.push({ dx,dy });
		}
	}
}

//map갱신
void fall() {
	for (int j = 0; j < 6; j++) {
		//남은 것들을 역순으로 담음
		stack<int> line;
		for (int i = 0; i < 12; i++) {
			if (map[i][j] == '.') continue;
			line.push(map[i][j]);
		}

		//다시 집어넣음. 나머지는 빈공간으로 채움
		for (int i = 11; i >= 0; i--) {
			int c = '.';
			if (!line.empty()) {
				c = line.top();
				line.pop();
			}
			map[i][j] = c;
		}
	}
}

int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++)
			cin >> map[i][j];
	}

	while (1) {
		bool flag = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] == '.') continue;
				if (check(i, j, map[i][j])) {
					puyo(i, j, map[i][j]);
					flag = true;
				}
			}
		}
		if (!flag) break;
		fall();
		result++;
	}
	cout << result;
	return 0;
}