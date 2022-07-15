#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node { int x, y, lev; };
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

bool bfs(int x, int y, vector<string> place) {
	queue<Node> q;
	int used[5][5];
	q.push({ x,y,0 });
	used[x][y] = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int lev = q.front().lev;
		q.pop();

		if (lev >= 2) break;

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= 5 || dy >= 5) continue;
			if (used[dx][dy] == 1) continue;
			if (place[dx][dy] == 'X') continue;
			if (place[dx][dy] == 'P') return false;
			used[dx][dy] = 1;
			q.push({ dx,dy,lev + 1 });
		}
	}
	return true;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (int p = 0; p < places.size(); p++) {
		int result = 1;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (places[p][i][j] != 'P') continue;
				if (!bfs(i, j, places[p])) {
					result = 0;
					break;
				}
			}
		}
		answer.push_back(result);
	}
	return answer;
}

int main() {
	vector<vector<string>> places = {
		{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
		{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
		{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
		{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
		{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
	};
	vector<int> answer = solution(places);
	for (int i = 0; i < 5; i++)
		cout << answer[i] << " ";
	return 0;
}