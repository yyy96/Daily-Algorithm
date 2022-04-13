#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 21e8
using namespace std;

struct Node {
	int x, y;
	int lev;
	int time;
};
int k, w, h;
int arr[200][200];
int used[200][200][30];
int direct[8][2] = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{2,1},{1,2} };
int direct2[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int minCnt = INF;

void bfs() {
	queue<Node> q;
	q.push({ 0,0,0,0 });
	used[0][0][0] = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int lev = q.front().lev;
		int time = q.front().time;
		q.pop();

		if (x == w - 1 && y == h - 1) {
			minCnt = min(minCnt, lev);
			continue;
		}

		if (time < k) {
			for (int i = 0; i < 8; i++) {
				int dx = x + direct[i][0];
				int dy = y + direct[i][1];
				if (dx < 0 || dy < 0 || dx >= w || dy >= h) continue;
				if (arr[dx][dy] == 1) continue;
				if (used[dx][dy][time + 1] == 1) continue;
				used[dx][dy][time + 1] = 1;
				//[dx][dy][lev] 로 하면 안되는 이유
				//: 나도 2번째에 여길 도착했는데, 다른 얘도 2번째에 이 자리에 들어올 수 있음.
				q.push({ dx,dy,lev + 1,time + 1 });
			}
		}
		for (int i = 0; i < 4; i++) {
			int dx = x + direct2[i][0];
			int dy = y + direct2[i][1];
			if (dx < 0 || dy < 0 || dx >= w || dy >= h) continue;
			if (arr[dx][dy] == 1) continue;
			if (used[dx][dy][time] == 1) continue;
			used[dx][dy][time] = 1;
			q.push({ dx,dy,lev + 1,time });
		}
	}
}

int main() {
	cin >> k;
	cin >> h >> w;

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++)
			cin >> arr[i][j];
	}

	bfs();

	if (minCnt == INF) cout << "-1";
	else cout << minCnt;

	return 0;
}