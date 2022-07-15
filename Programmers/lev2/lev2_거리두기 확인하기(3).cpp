#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int used[5][5];

bool dfs(int lev, int x, int y, vector<string> place) {
	if (lev > 2)  return true;
	if (lev > 0 && place[x][y] == 'P') return false;

	for (int i = 0; i < 4; i++) {
		int dx = x + direct[i][0];
		int dy = y + direct[i][1];
		if (dx < 0 || dy < 0 || dx >= 5 || dy >= 5) continue;
		if (used[dx][dy] == 1) continue;
		if (place[dx][dy] == 'X') continue;

		used[dx][dy] = 1;
		if (!dfs(lev + 1, dx, dy, place)) return false;
		used[dx][dy] = 0;
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
				memset(used, 0, sizeof(used));
				used[i][j] = 1;
				if (!dfs(0, i, j, places[p])) {
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