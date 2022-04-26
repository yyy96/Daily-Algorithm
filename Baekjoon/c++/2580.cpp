#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
	int x, y;
	int n;
};
int arr[9][9];
vector<Node> blanck;
int printFlag = 0;

void result() {
	printFlag = 1;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

vector<int> checkLine(vector<int> used, int x, int y) {
	for (int i = 0; i < 9; i++) {
		used[arr[x][i]] = 1;
		used[arr[i][y]] = 1;
	}
	return used;
}

vector<int> checkSquare(vector<int> used, int x, int y) {
	x = x - (x % 3);
	y = y - (y % 3);
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++)
			used[arr[i][j]] = 1;
	}
	return used;
}

void dfs(int lev) {
	//lev = 빈칸의 총 개수
	if (lev == blanck.size()) {
		result();
		return;
	}
	if (printFlag == 1) return;

	//현재 빈칸의 위치
	int x = blanck[lev].x;
	int y = blanck[lev].y;

	//사용가능한 숫자 확인
	//used 를 전역으로 설정하면 또 backup이 필요하다.
	vector<int> used(10);
	int backup[9][9];
	memcpy(backup, arr, 4 * 81);

	used = checkLine(used, x, y);
	used = checkSquare(used, x, y);

	//branch = 넣을 수 있는 숫자 1~9
	for (int i = 1; i < 10; i++) {
		if (used[i] == 1) continue;
		arr[x][y] = i;
		dfs(lev + 1);
		arr[x][y] = 0;
		memcpy(arr, backup, 4 * 81);
	}

}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				blanck.push_back({ i,j });
		}
	}

	dfs(0);
	return 0;
}