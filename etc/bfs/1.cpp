#include <iostream>
#include <queue>
using namespace std;

// 동시에 같이 움직이니까 같이 관리 (q도 1개)
struct Node {
	int ax, ay;
	int bx, by;
	int lev;
};
queue<Node> q;
int aDirect[5][2] = { {-1,0},{1,0},{0,0},{0,-1},{0,1} };
int bDirect[4][2] = { {-1,-1},{-1,1},{1,1},{1,-1} };
int used[4][6][4][6];     //used[Ax][Ay][Bx][By]
int map[4][6] = {
	1,-1,0,0,0,0,
	0,-1,0,-1,-1,0,
	0,0,0,0,0,0,
	0,-1,0,0,-1,1
};

int ff() {
	while (!q.empty()) {
		int ax = q.front().ax;
		int ay = q.front().ay;
		int bx = q.front().bx;
		int by = q.front().by;
		int lev = q.front().lev;
		if (ax == bx && ay == by) return lev;
		q.pop();

		// ↑↗, ↑↘, ↑↖, ↑↙, ..... 이런 경우의 수 20가지를 고려해야해서 2중 for문
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 4; j++) {
				int adx = ax + aDirect[i][0];
				int ady = ay + aDirect[i][1];
				int bdx = bx + bDirect[j][0];
				int bdy = by + bDirect[j][1];

				if (adx < 0 || ady < 0 || adx >= 4 || ady >= 6) continue;
				if (bdx < 0 || bdy < 0 || bdx >= 4 || bdy >= 6) continue;
				if (map[adx][ady] == -1 || map[bdx][bdy] == -1) continue;
				if (used[adx][ady][bdx][bdy] == 1) continue;
				used[adx][ady][bdx][bdy] = 1;

				q.push({ adx,ady,bdx,bdy, lev + 1 });
			}
		}
	}
	return 0;
}

int main() {
	q.push({ 0,0,3,5 });
	int cnt = ff();
	cout << cnt;

	return 0;
}