#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Team { int a, b; };
int score[6][3];
int input[6][3][4];
int result[4] = { 0, };

vector<Team> team;
int path[2];

bool isValid(int test) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			if (input[i][j][test] != score[i][j]) return false;
		}
	}
	return true;
}

//���� ���� �� �ִ� ����
void scoreDfs(int lev) {
	if (lev == team.size()) {
		//���� ���� score�� input �߿� �ִٸ� �ش� result�� 1ó��
		for (int t = 0; t < 4; t++) {
			if (result[t] == 1) continue;
			if (isValid(t)) result[t] = 1;
		}
		return;
	}

	//����
	score[team[lev].a][0]++; score[team[lev].b][2]++;
	scoreDfs(lev + 1);
	score[team[lev].a][0]--; score[team[lev].b][2]--;

	//�н�
	score[team[lev].a][2]++; score[team[lev].b][0]++;
	scoreDfs(lev + 1);
	score[team[lev].a][2]--; score[team[lev].b][0]--;

	//����
	score[team[lev].a][1]++; score[team[lev].b][1]++;
	scoreDfs(lev + 1);
	score[team[lev].a][1]--; score[team[lev].b][1]--;
}

//���� ����� �� �ִ� ����� ����
void gameDfs(int lev, int start) {
	if (lev == 2) {
		team.push_back({ path[0], path[1] });
		return;
	}

	for (int i = start; i < 6; i++) {
		path[lev] = i;
		gameDfs(lev + 1, i + 1);
		path[lev] = 0;
	}
}

int main() {
	for (int t = 0; t < 4; t++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++)
				cin >> input[i][j][t];
		}
	}
	gameDfs(0, 0);
	scoreDfs(0);
	for (int i = 0; i < 4; i++)
		cout << result[i] << " ";
}