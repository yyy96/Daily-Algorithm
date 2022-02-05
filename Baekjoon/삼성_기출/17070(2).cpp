#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

enum dir {
	w, c, l
};
int n;
int arr[17][17];
int direct[3][2] = { {0,1},{1,1},{1,0} }; //���� �밢�� ����
int cnt = 0;

bool check(int dx, int dy, int dir) {
	if (dir == w || dir == l) {
		if (dx < 0 || dy < 0 || dx >= n || dy >= n) return false;
		if (arr[dx][dy] == 1) return false;
	}
	else if (dir == c) {
		if (dx < 0 || dy < 0 || dx >= n || dy >= n) return false;
		if (arr[dx - 1][dy] == 1 || arr[dx][dy - 1] == 1 || arr[dx][dy] == 1) return false;
	}
	return true;
}

void dfs(int x, int y, int dir) {
	if (x == n - 1 && y == n - 1) { //lev �� ��� �Ǵ� ��ſ�, ������ ������ �ʿ�.
		cnt++;
		return;
	}

	if (dir == w) {
		for (int i = 0; i < 2; i++) { //branch �� ����. (���⿡ ���� branch ������ �ٸ� ����)
			int dx = x + direct[i][0]; int dy = y + direct[i][1];
			if (!check(dx, dy, i)) continue;
			dfs(dx, dy, i);
		}
	}
	if (dir == l) {
		for (int i = 1; i < 3; i++) {
			int dx = x + direct[i][0]; int dy = y + direct[i][1];
			if (!check(dx, dy, i)) continue;
			dfs(dx, dy, i);
		}
	}
	if (dir == c) {
		for (int i = 0; i < 3; i++) {
			int dx = x + direct[i][0]; int dy = y + direct[i][1];
			if (!check(dx, dy, i)) continue;
			dfs(dx, dy, i);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	dfs(0, 1, 0);
	cout << cnt;

	return 0;
}