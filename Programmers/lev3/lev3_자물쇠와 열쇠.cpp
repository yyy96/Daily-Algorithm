#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int openCnt = 0;
vector<vector<int>> board;

//���� ���谡 �����ǿ��� ��� ������ �� �� �ִ°�
bool isOpen(int x, int y, vector<vector<int>> key) {
	//board == 1 && key == 1 (X)    1,0 �̸� ���x
	//board == 0 && key == 1 (O)    0,0 �̸� false;
	//board == -1(����) �̶�� ����. (0���� �ʱ�ȭ�߾����� ������ cnt���� ȥ������ �� ������ ����)
	int cnt = 0; //�� ���� ������ ������ (�Ϻδ� ��ġ�ϴµ� �������� �ȿ��� ������ ���� �� ����)

	//board�� ������(���� ���� ����)���� Ű ũ�⸸ŭ Ȯ��
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

//���� ȸ��
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
	m = key.size();  //���� ũ��
	n = lock.size(); //�ڹ��� ũ��
	int boardSize = 2 * (m - 1) + n;
	board.resize(boardSize, vector<int>(boardSize, -1));

	//�����ǿ� �ڹ��� �Է�
	int x = m - 1, y = m - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (lock[i][j] == 0) openCnt++;
			board[x + i][y + j] = lock[i][j];
		}
	}

	//�������� ��� ��ǥ���� 4���⿡ ���� ���� Ž��
	for (int i = 0; i < m + n - 1; i++) {
		for (int j = 0; j < m + n - 1; j++) {
			for (int d = 0; d < 4; d++) {
				turn(key); //key ȸ��
				if (!isOpen(i, j, key)) continue; //(i.j)���� key�� �����°�
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