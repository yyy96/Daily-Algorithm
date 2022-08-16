#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1501
using namespace std;

struct Node {
	int x, y;
	int lev;
};
int r, c;
char map[MAX][MAX];
int visted[MAX][MAX] = { 0, };
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
vector<Node> LS;
bool meetFlag = false;

queue<Node> meet(queue<Node> nowL) {
	queue<Node> nextL;
	nowL.push(nowL.front());
	visted[nowL.front().x][nowL.front().y] = 1;

	while (!nowL.empty()) {
		int x = nowL.front().x;
		int y = nowL.front().y;
		nowL.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= r || dy >= c) continue;
			if (visted[dx][dy] == 1) continue;
			if (dx == LS[1].x && dy == LS[1].y) {
				meetFlag = true;
				break;
			}
			if (map[dx][dy] == 'X') nextL.push({ dx,dy });
			if (map[dx][dy] == '.') nowL.push({ dx,dy });
			visted[dx][dy] = 1;
		}
	}
	return nextL;
}

int bfs(queue<Node> q, Node L1) {
	int used[MAX][MAX] = { 0, };
	int yersterday = 0;
	queue<Node> L;
	L.push(L1);

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int lev = q.front().lev;
		q.pop();

		if (lev > yersterday) {
			L = meet(L);
			if (meetFlag) return lev;
			yersterday = lev;
		}

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= r || dy >= c) continue;
			if (map[dx][dy] == '.') continue;
			if (used[dx][dy] == 1) continue;
			used[dx][dy] = 1;
			map[dx][dy] = '.';
			q.push({ dx,dy,lev + 1 });
		}
	}
	return 0;
}

int main() {
	cin >> r >> c;

	queue<Node> water;
	string str;
	for (int i = 0; i < r; i++) {
		cin >> str;
		for (int j = 0; j < c; j++) {
			map[i][j] = str[j];
			if (str[j] != 'X') water.push({ i,j,0 });
			if (str[j] == 'L') LS.push_back({ i,j });
		}
	}

	cout << bfs(water, LS[0]);
	return 0;
}