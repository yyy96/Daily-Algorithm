#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 51
using namespace std;

struct Node {
	int x, y;
};
int n, l, r;
int map[MAX][MAX];
bool moving[MAX][MAX] = { false, };
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
queue<Node> path;
int breakFlag = 0;

void movingPeople(int country, int people) {
	while (!path.empty()) {
		Node now = path.front();
		path.pop();
		map[now.x][now.y] = people / country;
	}
}

void bfs(int sx, int sy) {
	int country = 0, people = 0;
	bool visited[MAX][MAX] = { false, };
	queue<Node> q;
	q.push({ sx,sy });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
			if (l > abs(map[x][y] - map[dx][dy]) || abs(map[x][y] - map[dx][dy]) > r) continue;
			//무한 루프 방지 + 이미 이주한 나라는 고려x
			if (visited[dx][dy] || moving[dx][dy]) continue;
			visited[dx][dy] = true;
			moving[dx][dy] = true;
			people += map[dx][dy];
			country++;
			path.push({ dx,dy });
			q.push({ dx,dy });
		}
	}

	if (!path.empty()) movingPeople(country, people);
	else breakFlag++; //이동을 안한 나라를 count해서 모든 나라가 이동을 안했을 경우 종료
	return;
}

int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	int days = 0;
	while (1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (moving[i][j]) continue;
				bfs(i, j);
			}
		}
		//break 조건 (모든 칸에서 이동한 적이 없으면 종료)
		if (breakFlag == n * n) break;
		else breakFlag = 0;
		days++;
		memset(moving, false, sizeof(moving));
	}
	cout << days;
}