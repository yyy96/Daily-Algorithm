#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 11
using namespace std;

struct Ball {
	int x, y;
};
struct Node {
	Ball r, b;
	int cnt;
};
int n, m;
char map[MAX][MAX];
int visted[MAX][MAX][MAX][MAX];
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
Ball red, blue;

Ball move(Ball ball, int dir) {
	queue<Ball> q;
	q.push(ball);

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		int dx = x + direct[dir][0];
		int dy = y + direct[dir][1];
		if (map[dx][dy] == 'O') return { dx,dy }; //여기 주의
		if (map[dx][dy] == '#') return { x,y };
		q.push({ dx,dy });
	}
}


int bfs() {
	queue<Node> q;
	q.push({ red, blue, 0 });
	map[red.x][red.y] = '.';
	map[blue.x][blue.y] = '.';
	visted[red.x][red.y][blue.x][blue.y] = 1;

	while (!q.empty()) {
		Ball R = q.front().r;
		Ball B = q.front().b;
		int cnt = q.front().cnt;
		q.pop();

		if (cnt >= 10) break;
		for (int i = 0; i < 4; i++) {
			Ball r = move(R, i);
			Ball b = move(B, i);

			if (map[b.x][b.y] == 'O') continue;
			if (map[r.x][r.y] == 'O') return cnt + 1;
			if (r.x == b.x && r.y == b.y) {
				int moveR = abs(R.x - r.x) + abs(R.y - r.y);
				int moveB = abs(B.x - b.x) + abs(B.y - b.y);
				if (moveR < moveB) {
					b.x -= direct[i][0]; b.y -= direct[i][1];
				}
				else {
					r.x -= direct[i][0]; r.y -= direct[i][1];
				}
			}
			if (visted[r.x][r.y][b.x][b.y] == 1) continue;
			visted[r.x][r.y][b.x][b.y] = 1;
			q.push({ r, b, cnt + 1 });
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'R') red = { i,j };
			if (map[i][j] == 'B') blue = { i,j };
		}
	}

	cout << bfs();
	return 0;
}