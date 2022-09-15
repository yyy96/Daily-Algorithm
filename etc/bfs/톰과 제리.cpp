#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100
using namespace std;

struct Node {
	int x, y;
	int dir, lev;
};
int n;
int map[MAX][MAX];
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
Node T, J;

int bfs() {
	int visted[MAX][MAX] = { 0, }; //최소 몇 회의 turn 으로 도착했는가.
	queue<Node> q;
	q.push({ T.x ,T.y,-1,0 });
	int minturn = MAX;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = now.x + direct[i][0];
			int dy = now.y + direct[i][1];
			int newlev = now.lev;
			if (now.dir != i) newlev++;
			if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
			if (map[dx][dy] == 1) continue;
			if (visted[dx][dy] != 0 && visted[dx][dy] < newlev) continue;
			if (dx == J.x && dy == J.y) {
				minturn = min(newlev, minturn);
				continue;
			}
			visted[dx][dy] = newlev;
			q.push({ dx,dy,i, newlev });
		}
	}
	if (minturn == MAX) return -1;
	return minturn - 1;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	cin >> T.x >> T.y >> J.x >> J.y;
	T.x -= 1; T.y -= 1; J.x -= 1; J.y -= 1;
	cout << bfs();
	return 0;
}