#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int openCnt = 0;
vector<vector<int>> board;

//현재 열쇠가 보드판에서 모든 구멍을 열 수 있는가
bool isOpen(int x, int y, vector<vector<int>> key) {
	//board == 1 && key == 1 (X)    1,0 이면 상관x
	//board == 0 && key == 1 (O)    0,0 이면 false;
	//board == -1(여백) 이라면 무시. (0으로 초기화했었으면 오히려 cnt값에 혼동생길 수 있음을 주의)
	int cnt = 0; //몇 개의 구멍을 열었나 (일부는 일치하는데 나머지는 안열린 공간이 있을 수 있음)

	//board의 시작점(여백 공백 포함)에서 키 크기만큼 확인
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (board[x + i][y + j] == 1 && key[i][j] == 1) return false;
			if (board[x + i][y + j] == 0 && key[i][j] == 0) return false;
			if (board[x + i][y + j] == 0 && key[i][j] == 1) cnt++;
		}
	}
	if (cnt == openCnt) return true;
	return false;
}

//열쇠 회전
void turn(vector<vector<int>> &key) {
	vector<vector<int>> temp = key;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++)
			temp[i][j] = key[m - 1 - j][i];\
	}
	key = temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	m = key.size();  //열쇠 크기
	n = lock.size(); //자물쇠 크기
	int boardSize = 2 * (m - 1) + n;
	board.resize(boardSize, vector<int>(boardSize, -1));

	//보드판에 자물쇠 입력
	int x = m - 1, y = m - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (lock[i][j] == 0) openCnt++;
			board[x + i][y + j] = lock[i][j];
		}
	}

	//보드판의 모든 좌표에서 4방향에 대한 완전 탐색
	for (int i = 0; i < m + n - 1; i++) {
		for (int j = 0; j < m + n - 1; j++) {
			for (int d = 0; d < 4; d++) {
				turn(key); //key 회전
				if (!isOpen(i, j, key)) continue; //(i.j)에서 key가 열리는가
				return true;
			}
		}
	}
	return answer;
}

int main() {
	vector<vector<int>> key = { {0,0,0},{1,0,0},{0,1,1} };
	vector<vector<int>> lock = { {1,1,1},{1,1,0},{1,0,1} };
	cout << solution(key, lock);
	return 0;
}