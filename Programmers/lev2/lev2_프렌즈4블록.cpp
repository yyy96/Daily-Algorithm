#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Block {
	int x, y;
};
int direct[4][2] = { {0,0}, {1,0},{1,1},{0,1} }; //왼위 기준
int result = 0;

vector<Block> findblock(int m, int n, vector<vector<char>> board) {
	vector<Block> block;

	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (board[i][j] == 'x') continue;
			bool square = true;
			for (int d = 0; d < 4; d++) {
				int dx = i + direct[d][0];
				int dy = j + direct[d][1];
				if (dx >= m || dy >= n) continue;
				if (board[dx][dy] != board[i][j]) {
					square = false;
					break;
				}
			}
			if (square) block.push_back({ i,j });
		}
	}
	return block;
}

vector<vector<char>> eraseblock(int m, int n, vector<Block> block, vector<vector<char>> board) {

	//erase
	for (int i = 0; i < block.size(); i++) {
		int x = block[i].x;
		int y = block[i].y;
		for (int d = 0; d < 4; d++) {
			int dx = x + direct[d][0];
			int dy = y + direct[d][1];
			if (board[dx][dy] == 'x') continue;
			board[dx][dy] = 'x';
			result++;
		}
	}

	//fall
	for (int y = 0; y < n; y++) {
		for (int x = m - 1; x > 0; x--) {
			if (board[x][y] != 'x') continue;
			for (int i = x - 1; i >= 0; i--) {
				if (board[i][y] == 'x') continue;
				board[x][y] = board[i][y];
				board[i][y] = 'x';
				break;
			}
		}
	}
	return board;
}


int solution(int m, int n, vector<string> board) {
	vector<vector<char>> b(m*n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			b[i].push_back(board[i][j]);
	}

	//더 이상 사라지지 못할 때까지.
	while (1) {
		vector<Block> block = findblock(m, n, b);
		if (block.size() == 0) break;

		b = eraseblock(m, n, block, b);
	}

	return result;
}

int main() {
	int m = 5;
	int n = 6;
	vector<string> board = { "AAAAAA","BBAATB","BBAATB","JJJTAA","JJJTAA" };
	//vector<string> board = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
	cout << solution(m, n, board);
	return 0;
}