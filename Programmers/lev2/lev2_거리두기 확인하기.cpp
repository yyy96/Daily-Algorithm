#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Node {
	int x, y;
};

bool distancing(vector<Node> p, vector<string> place) {
	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j < p.size(); j++) {
			if (i == j) continue;
			Node p1 = p[i];
			Node p2 = p[j];
			if (abs(p1.x - p2.x) + abs(p1.y - p2.y) > 2) continue;
			if (abs(p1.x - p2.x) + abs(p1.y - p2.y) <= 1) return false;

			//거리가 2이면 파티션이 주변에 있는지 check
			if (p1.x == p2.x && p1.y < p2.y) {
				if (place[p1.x][p1.y + 1] == 'O') return false;
			}
			if (p[i].y == p2.y && p1.x < p2.x) {
				if (place[p1.x + 1][p1.y] == 'O') return false;
			}
			if (p1.x < p2.x && p1.y < p2.y) {
				if (place[p1.x][p2.y] == 'O') return false;
				if (place[p2.x][p1.y] == 'O') return false;
			}
			if (p1.x <p2.x && p1.y > p2.y) {
				if (place[p1.x][p2.y] == 'O') return false;
				if (place[p2.x][p1.y] == 'O') return false;
			}

		}
	}
	return true;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (int i = 0; i < 5; i++) {
		vector<Node> p;
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				if (places[i][x][y] == 'P')
					p.push_back({ x,y });
			}
		}
		if (distancing(p, places[i])) answer.push_back(1);
		else answer.push_back(0);
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