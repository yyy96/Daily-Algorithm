#include <iostream>
#include <vector>
#define MAX 26
using namespace std;

int n, m;
int map[MAX][MAX];
int cnt = 0;

bool check(int x, int y) {
	if (x == 0 || y == 0) return true;
	if (map[x - 1][y] && map[x][y - 1] && map[x - 1][y - 1]) return false;
	return true;
}

void dfs(int x, int y) {
	if (y == m) {
		if (x == n - 1) {
			cnt++;
			return;
		}
		y = 0; x++;
	}

	map[x][y] = 1;
	if (check(x, y)) dfs(x, y + 1);
	map[x][y] = 0;
	dfs(x, y + 1);   // 넴모를 올리지않는 경우
}

int main() {
	cin >> n >> m;
	dfs(0, 0);
	cout << cnt;
	return 0;
}