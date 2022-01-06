#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int x, y;
	int time;
};
struct Water {
	int x, y;
};
int R, C;
char arr[51][51];
int direction[4][2] = {
	{-1,0},{1,0},{0,1},{0,-1}
};
Node s, e;
queue<Node> q;
queue<Water>water;

void flood() {
	int waterSize = water.size();
	for (int i = 0; i < waterSize; i++) {
		int x = water.front().x;
		int y = water.front().y;
		water.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + direction[i][0];
			int dy = y + direction[i][1];
			if (dx < 0 || dy < 0 || dx >= R || dy >= C) continue;
			if (arr[dx][dy] == '.') {
				arr[dx][dy] = '*';
				water.push({ dx,dy });
			}
		}
	}
}

int fun() {
	q.push({ s.x, s.y, 0 });

	while (!q.empty()) {
		flood();
		int thisTimeMove = q.size();
		for (int t = 0; t < thisTimeMove; t++) {
			int x = q.front().x;
			int y = q.front().y;
			int time = q.front().time;
			q.pop();
			if (x == e.x&&y == e.y) return time;

			for (int i = 0; i < 4; i++) {
				int dx = x + direction[i][0];
				int dy = y + direction[i][1];
				if (dx < 0 || dy < 0 || dx >= R || dy >= C) continue;
				if (arr[dx][dy] == 'X' || arr[dx][dy] == '*'|| arr[dx][dy]=='S') continue;
				arr[dx][dy] = 'S';
				q.push({ dx,dy,time + 1 });
			}
		}
	}
	return -1;
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				s.x = i;
				s.y = j;
			}
			else if (arr[i][j] == 'D') {
				e.x = i;
				e.y = j;
			}
			else if (arr[i][j] == '*') {
				water.push({ i,j });
			}
		}
	}

	int result = fun();
	if (result == -1) cout << "KAKTUS";
	else cout << result;

	return 0;
}