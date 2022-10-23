#include <iostream>
#include <algorithm>
#define MAX 16
using namespace std;

int n;
int map[MAX][MAX] = { 0, };
int y[MAX] = { 0, };
int cnt = 0;

bool check(int x, int y) {
	//이전 x에 놓인 퀸들만 확인해보면 된다.(크로스 ↖, ↗ 방향)
	for (int i = x; i >= 0; i--) {
		if ((x - i >= 0 && y - i >= 0 && x - i < n && y - i < n) && (map[x - i][y - i] == 1)) return false;
		if ((x - i >= 0 && y + i >= 0 && x - i < n && y + i < n) && (map[x - i][y + i] == 1)) return false;
	}
	return true;
}

void dfs(int x) {
	if (x == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (y[i] == 1) continue;
		if (!check(x, i)) continue;
		y[i] = 1;
		map[x][i] = 1;
		dfs(x + 1);
		map[x][i] = 0;
		y[i] = 0;
	}
}


int main()
{
	cin >> n;
	dfs(0);
	cout << cnt;
	return 0;
}