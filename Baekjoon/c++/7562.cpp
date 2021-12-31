#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int x, y;
	int lev;
};
int direct[8][2] = {
	{-1,-2},{-1,2},{-2,-1},{-2,1},{1,-2},{1,2},{2,-1},{2,1}
};
int n;
int T;
int X, Y;

int fun(int x, int y) {
	int chess[301][301] = { 0, };
	queue<Node> q;
	q.push({ x,y,0 });
	chess[x][y] = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int lev = q.front().lev;
		if (x == X && y == Y) {
			return lev;
		}
		q.pop();

		for (int i = 0; i < 8; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
			if (chess[dx][dy] == 1) continue;
			chess[dx][dy] = 1;
			q.push({ dx,dy,lev + 1 });
		}
	}
	return -1;
}

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		int x, y;
		cin >> n;
		cin >> x >> y;
		cin >> X >> Y;
		cout << fun(x, y)<<endl;
	}
	return 0;
}