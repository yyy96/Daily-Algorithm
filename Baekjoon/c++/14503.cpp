#include <iostream>
#include <algorithm>
#define MAX 51
using namespace std;

int map[MAX][MAX];
int direct[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; //방향 설정해서 순서 정렬
int n, m;
int cnt = 1;

void dfs(int x, int y, int dir) {

	for (int i = 0; i < 4; i++) {
		int newdir = (dir + 3 - i) % 4; // (dir+i<4)? dir+i : dir -i; 해서 오답
		int dx = x + direct[newdir][0];
		int dy = y + direct[newdir][1];

		//2.벽이거나 청소했으면 회전
		if (dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
		if (map[dx][dy] != 0) continue;
		//1. 청소, 전진
		map[dx][dy] = 2;
		cnt++; //lev이 아니라 cnt로 계산
		dfs(dx, dy, newdir);
	}

	//3.방향 모두 실패 : 한 칸 후진
	int backdir = (dir + 2 < 4) ? dir + 2 : dir - 2;
	int bx = x + direct[backdir][0];
	int by = y + direct[backdir][1];
	//4. 후진 불가 : 종료
	if (map[bx][by] == 1) {
		cout << cnt;
		exit(0);
	}
	else dfs(bx, by, dir);
}

int main()
{
	int r, c, d;
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	map[r][c] = 2;
	dfs(r, c, d);
	return 0;
}