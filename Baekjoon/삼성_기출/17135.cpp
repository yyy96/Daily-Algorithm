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
			if (enemy[i].kill) continue; //죽거나 성에 도착했으면 제외.
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
	//모든 적이 판에서 사라지면(죽거나, 성에 도착하거나)

	while (1) {
		if (fin(enemy)) break;

		//모든 궁수들이 1번씩 가장 가까운 적(타겟) 찾기
		vector<Node> tar = findTar(enemy);

		//shoot
		for (int j = 0; j < 3; j++) {
			if (tar[j].x == 0 && tar[j].y == 0) continue; //가장 가까운 사람이 없는 상태
			for (int i = 0; i < enemy.size(); i++) {
				if (enemy[i].kill) continue; //동시에 다른 궁수가 죽임
				if (enemy[i].x == tar[j].x && enemy[i].y == tar[j].y) {
					enemy[i].kill = true;
					cnt++;
					break;
				}
			}
		}

		//턴이 끝나면 적들 한칸씩 전진
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