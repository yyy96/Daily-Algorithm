#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int x, y;
};
int board[9][9];
vector<Node> zeros;
bool finshFlag = false;

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}

bool checkline(Node zero, int n) {
	//세로 체크
	for (int i = 0; i < 9; i++)
		if (n == board[zero.x][i]) return false;

	//가로 체크
	for (int i = 0; i < 9; i++)
		if (n == board[i][zero.y]) return false;
	return true;
}

bool checksquare(Node zero, int n) {
	int x = 3 * (zero.x / 3);
	int y = 3 * (zero.y / 3);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (n == board[x + i][y + j]) return false;
		}
	}
	return true;
}

void dfs(int lev) {
	if (finshFlag) return;
	if (lev == zeros.size()) {
		print();
		finshFlag = true;
		return;
	}

	Node zero = zeros[lev];
	for (int i = 1; i <= 9; i++) {
		if (!checkline(zero, i)) continue;
		if (!checksquare(zero, i)) continue;
		board[zero.x][zero.y] = i;
		dfs(lev + 1);
		board[zero.x][zero.y] = 0;
	}
}

int main()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0)
				zeros.push_back({ i,j });
		}
	}
	dfs(0);
	return 0;
}