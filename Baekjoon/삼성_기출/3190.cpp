#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#define MAX 102
using namespace std;

struct Node {
	int x, y;
};
struct Direct {
	int t;
	char d;
};
int n, k, l;
int map[MAX][MAX] = { 0, };
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }; //시계방향
int dir = 0;
int time = 0;
queue<Direct> nextDirect;


int bfs() {
	deque<Node> q;
	q.push_front({ 0,0 });

	Direct nextDir = nextDirect.front();
	nextDirect.pop();

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;

		if (time == nextDir.t) {
			if (nextDir.d == 'L') dir -= 1;
			if (nextDir.d == 'D') dir += 1;
			if (dir < 0) dir += 4;
			if (dir >= 4) dir -= 4;

			if (!nextDirect.empty()) {
				nextDir = nextDirect.front();
				nextDirect.pop();
			}
		}
		int dx = x + direct[dir][0];
		int dy = y + direct[dir][1];
		if (dx < 0 || dy < 0 || dx >= n || dy >= n) return time + 1;
		for (int i = 0; i < q.size(); i++) { 		//꼬리+몸을 밟지 않는지 확인
			if (dx == q[i].x && dy == q[i].y) return time + 1;
		}
		if (map[dx][dy] == 1) map[dx][dy] = 0; 		//사과를 먹는 경우, 머리만 전진
		else q.pop_back();		                    //사과를 먹지 않는 경우, 꼬리 이동
		q.push_front({ dx,dy });
		time++;
	}
	return -1;
}


int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int t; char d;
		cin >> t >> d;
		nextDirect.push({ t, d });
	}
	cout << bfs();
	return 0;
}