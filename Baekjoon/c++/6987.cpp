#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int team[6][3];
int result[4];

int solution() {
	//조건1. 각 나라의 승+무+패 = 5
	for (int i = 0; i < 6; i++) {
		if (team[i][0] + team[i][1] + team[i][2] != 5)
			return 0;
	}

	//조건2. 총 발생한 '무' 횟수는 홀수일 수 없다.
	int same = 0;
	for (int i = 0; i < 6; i++) {
		same += team[i][1];
	}
	if (same % 2 != 0) return 0;

	//조건2-1. 무가 짝수여도 나라의 개수가 홀 수이면 안된다.
	int ssame = 0, scnt = 0;
	for (int i = 0; i < 6; i++) {
		if (team[i][1] != 0) scnt++;
		if (scnt % 2 != 0) ssame += team[i][1];
		else ssame -= team[i][1];
	}
	if (ssame != 0) return 0;

	//조건3. 총 승 = 패의 수는 같아야한다.
	int win = 0, lose = 0;
	for (int i = 0; i < 6; i++) {
		win += team[i][0];
		lose += team[i][2];
	}
	if (win != lose) return 0;

	return 1;
}

int main() {
	for (int t = 0; t < 4; t++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++)
				cin >> team[i][j];
		}
		result[t] = solution();
	}
	for (int i = 0; i < 4; i++)
		cout << result[i] << " ";

	return 0;
}