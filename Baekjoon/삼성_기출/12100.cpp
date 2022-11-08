#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#define MAX 21
using namespace std;

int n;
int board[MAX][MAX];
int maxBlock = 0;

void moveUp() {
	for (int line = 0; line < n; line++) {
		int last = -1; deque<int> q;
		for (int i = 0; i < n; i++) {
			int now = board[i][line];
			board[i][line] = 0;
			if (now == 0) continue;
			if (last == -1) {
				last = now;
				q.push_back(now);
				continue;
			}

			if (last == now) {
				last = -1;
				q.pop_back();
				q.push_back(now * 2);
			}
			else {
				last = now;
				q.push_back(now);
			}
		}

		int i = 0;
		while (!q.empty()) {
			maxBlock = max(maxBlock, q.front());
			board[i][line] = q.front();
			q.pop_front();
			i++;
		}
	}
}

void moveDown() {
	for (int line = 0; line < n; line++) {
		int last = -1; deque<int> q;
		for (int i = n - 1; i >= 0; i--) {
			int now = board[i][line];
			board[i][line] = 0;
			if (now == 0) continue;
			if (last == -1) {
				last = now;
				q.push_back(now);
				continue;
			}

			if (last == now) {
				last = -1;
				q.pop_back();
				q.push_back(now * 2);
			}
			else {
				last = now;
				q.push_back(now);
			}
		}

		int i = n - 1;
		while (!q.empty()) {
			maxBlock = max(maxBlock, q.front());
			board[i][line] = q.front();
			q.pop_front();
			i--;
		}
	}
}

void moveLeft() {
	for (int line = 0; line < n; line++) {
		int last = -1; deque<int> q;
		for (int i = 0; i < n; i++) {
			int now = board[line][i];
			board[line][i] = 0;
			if (now == 0) continue;
			if (last == -1) {
				last = now;
				q.push_back(now);
				continue;
			}

			if (last == now) {
				last = -1;
				q.pop_back();
				q.push_back(now * 2);
			}
			else {
				last = now;
				q.push_back(now);
			}
		}

		int i = 0;
		while (!q.empty()) {
			maxBlock = max(maxBlock, q.front());
			board[line][i] = q.front();
			q.pop_front();
			i++;
		}
	}
}

void moveRight() {
	for (int line = 0; line < n; line++) {
		int last = -1; deque<int> q;
		for (int i = n - 1; i >= 0; i--) {
			int now = board[line][i];
			board[line][i] = 0;
			if (now == 0) continue;
			if (last == -1) {
				last = now;
				q.push_back(now);
				continue;
			}

			if (last == now) {
				last = -1;
				q.pop_back();
				q.push_back(now * 2);
			}
			else {
				last = now;
				q.push_back(now);
			}
		}

		int i = n - 1;
		while (!q.empty()) {
			maxBlock = max(maxBlock, q.front());
			board[line][i] = q.front();
			q.pop_front();
			i--;
		}
	}
}


void dfs(int lev) {
	if (lev == 5) {
		return;
	}

	int now[MAX][MAX];
	memcpy(now, board, sizeof(board));

	moveUp();
	dfs(lev + 1);
	memcpy(board, now, sizeof(board));

	moveDown();
	dfs(lev + 1);
	memcpy(board, now, sizeof(board));

	moveLeft();
	dfs(lev + 1);
	memcpy(board, now, sizeof(board));

	moveRight();
	dfs(lev + 1);
	memcpy(board, now, sizeof(board));
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	}
	dfs(0);
	cout << maxBlock;
	return 0;
}