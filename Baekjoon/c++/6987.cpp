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
	//����1. �� ������ ��+��+�� = 5
	for (int i = 0; i < 6; i++) {
		if (team[i][0] + team[i][1] + team[i][2] != 5)
			return 0;
	}

	//����2. �� �� = ���� ���� ���ƾ��Ѵ�.
	int win = 0, lose = 0;
	for (int i = 0; i < 6; i++) {
		win += team[i][0];
		lose += team[i][2];
	}
	if (win != lose) return 0;

	//����3-1. ���� �� Ƚ���� Ȧ���� �� ����.
	int same = 0;
	for (int i = 0; i < 6; i++) {
		same += team[i][1];
	}
	if (same % 2 != 0) return 0;

	//����3-2. ���� ������ �̷�������Ѵ�.
	same = 0;
	for (int i = 0; i < 6; i++) {
		if (same <=0 ) same += team[i][1];
		else same -= team[i][1];
	}
	if (same != 0) return 0;
	
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