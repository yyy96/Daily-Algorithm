#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

struct Shark {
	int x, y;
	int lev;
};
int n;
int arr[21][21];
int direct[4][2] = { {-1,0},{0,-1}, {0,1}, {1,0} }; //우선순위: 상>좌>우>하
int lasttime = 0;
int ssize = 2;
int eat = 0;

//ff 한번 먹고나면 종료
Shark bfs(int x, int y) {
	queue<Shark> q;
	Shark fish = { INF,INF,-1 };
	int used[21][21] = { 0, }; //초기화를 안해주면 오류가 발생할 수 있다.
	int firstEatTime = INF;
	q.push({ x,y,0 });

	while (!q.empty()) {
		Shark s = q.front();
		q.pop();

		if (arr[s.x][s.y] != 0 && arr[s.x][s.y] < ssize) {
			if (fish.lev != -1 && firstEatTime < s.lev) {
				return fish;
			}
			if (fish.x < s.x) continue; //더 아래x
			if (fish.x == s.x && fish.y < s.y) continue; //더 오른쪽x
			firstEatTime = s.lev;
			fish = s;
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int dx = s.x + direct[i][0];
			int dy = s.y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
			if (arr[dx][dy] > ssize) continue;
			if (used[dx][dy] == 1) continue;
			used[dx][dy] = 1;
			q.push({ dx,dy, s.lev + 1 });
		}
	}
	return fish;
}

int main() {
	cin >> n;

	Shark s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				s.x = i; s.y = j;
				arr[i][j] = 0;
			}
		}
	}

	while (1) {
		//마지막으로 있던(먹은) 위치
		s = bfs(s.x, s.y);
		if (s.lev == -1) break;
		arr[s.x][s.y] = 0;
		lasttime += s.lev;
		eat++;
		if (ssize == eat) {
			ssize++;
			eat = 0;
		}
	}
	cout << lasttime;
	return 0;
}