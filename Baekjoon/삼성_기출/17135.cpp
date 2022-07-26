#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 21e8
using namespace std;

struct Node {
	int x, y;
	bool kill;
};
int n, m, d;
int map[16][16];
int castle[16];
int person[3];
int result = 0;

bool fin(vector<Node> enemy) {
	for (int i = 0; i < enemy.size(); i++) {
		if (!enemy[i].kill) return false;
	}
	return true;
}

vector<Node> findTar(vector<Node> enemy) {
	vector<Node> tar(3);
	for (int j = 0; j < 3; j++) {
		int near = MAX;
		for (int i = 0; i < enemy.size(); i++) {
			if (enemy[i].kill) continue; //�װų� ���� ���������� ����.
			int distance = abs(n - enemy[i].x) + abs(person[j] - enemy[i].y);
			if (distance > d) continue;
			if (distance < near) {
				near = distance;
				tar[j] = enemy[i];
			}
			else if (distance == near) {
				if (tar[j].y > enemy[i].y)
					tar[j] = enemy[i];
			}
		}
	}
	return tar;
}

vector<Node> move(vector<Node> enemy) {
	for (int i = 0; i < enemy.size(); i++) {
		if (enemy[i].kill) continue;
		enemy[i].x++;
		if (enemy[i].x >= n) enemy[i].kill = true;
	}
	return enemy;
}

int shoot(vector<Node> enemy) {
	int cnt = 0;
	//��� ���� �ǿ��� �������(�װų�, ���� �����ϰų�)

	while (1) {
		if (fin(enemy)) break;

		//��� �ü����� 1���� ���� ����� ��(Ÿ��) ã��
		vector<Node> tar = findTar(enemy);

		//shoot
		for (int j = 0; j < 3; j++) {
			if (tar[j].x == 0 && tar[j].y == 0) continue; //���� ����� ����� ���� ����
			for (int i = 0; i < enemy.size(); i++) {
				if (enemy[i].kill) continue; //���ÿ� �ٸ� �ü��� ����
				if (enemy[i].x == tar[j].x && enemy[i].y == tar[j].y) {
					enemy[i].kill = true;
					cnt++;
					break;
				}
			}
		}

		//���� ������ ���� ��ĭ�� ����
		enemy = move(enemy);
	}
	return cnt;
}


void dfs(int lev, int start, vector<Node> enemy) {
	if (lev == 3) {
		int cnt = shoot(enemy);
		result = max(result, cnt);
		return;
	}

	for (int i = start; i < m; i++) {
		if (castle[i] == 1) continue;
		castle[i] = 1;
		person[lev] = i;
		dfs(lev + 1, i + 1, enemy);
		person[lev] = 0;
		castle[i] = 0;
	}
}

int main() {
	vector<Node> enemy;

	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				enemy.push_back({ i,j,false });
		}
	}

	dfs(0, 0, enemy);
	cout << result;
	return 0;
}