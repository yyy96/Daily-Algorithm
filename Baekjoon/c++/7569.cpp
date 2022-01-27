#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int x, y, h;
	int lev;
};
int n, m, h;
int arr[101][101][101] = { 0, };
int used[101][101][101] = { 0, };
int direct[6][3] = { {-1,0,0},{1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} }; // {x,y,h} 6방향
queue<Node> tomato;
bool allRipen = true;

int bfs() {
	int lev = -1;

	while (!tomato.empty()) {
		Node Tomato = tomato.front();
		lev = Tomato.lev;
		tomato.pop();

		for (int i = 0; i < 6; i++) {
			int dx = Tomato.x + direct[i][0];
			int dy = Tomato.y + direct[i][1];
			int dh = Tomato.h + direct[i][2];

			if (dx < 0 || dy < 0 || dh < 0 || dx >= n || dy >= m || dh >= h) continue;
			if (arr[dx][dy][dh] != 0) continue; //익지 않은 0인 토마토만 건드림
			if (used[dx][dy][dh] == 1) continue;
			used[dx][dy][dh] = 1;
			arr[dx][dy][dh] = 1; //익었다는걸 체크
			tomato.push({ dx,dy,dh,lev + 1 });
		}
	}

	return lev;
}

bool checkallRipen() {
	for (int t = 0; t < h; t++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j][t] == 0)
					return false;
			}
		}
	}
	return true;
}

int main() {
	cin >> m >> n >> h;

	for (int t = 0; t < h; t++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j][t];
				if (arr[i][j][t] == 1)
					tomato.push({ i,j,t,0 });
				else if (arr[i][j][t] == 0)
					allRipen = false;
			}
		}
	}

	if (allRipen)
		cout << 0;
	else {
		int minDay = bfs();
		if (checkallRipen()) cout << minDay;
		else cout << -1;
	}

	return 0;
}