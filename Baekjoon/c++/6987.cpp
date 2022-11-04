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

//서로 가질 수 있는 조합
void scoreDfs(int lev) {
	if (lev == team.size()) {
		//만약 현재 score가 input 중에 있다면 해당 result는 1처리
		for (int t = 0; t < 4; t++) {
			if (result[t] == 1) continue;
			if (isValid(t)) result[t] = 1;
		}
		return;
	}

	//승패
	score[team[lev].a][0]++; score[team[lev].b][2]++;
	scoreDfs(lev + 1);
	score[team[lev].a][0]--; score[team[lev].b][2]--;

	//패승
	score[team[lev].a][2]++; score[team[lev].b][0]++;
	scoreDfs(lev + 1);
	score[team[lev].a][2]--; score[team[lev].b][0]--;

	//무무
	score[team[lev].a][1]++; score[team[lev].b][1]++;
	scoreDfs(lev + 1);
	score[team[lev].a][1]--; score[team[lev].b][1]--;
}

//서로 경기할 수 있는 나라들 조합
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