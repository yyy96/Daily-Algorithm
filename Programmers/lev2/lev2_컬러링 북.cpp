#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Node {
	int x, y;
	int size;
};
int max_size;

vector<vector<int>> ff(int color, int x, int y, int m, int n, vector<vector<int>> picture) {
	int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
	queue<Node> q;
	int size = 1;
	q.push({ x, y, size });
	picture[x][y] = 0;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		if (max_size < size) max_size = size;

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= m || dy >= n) continue;
			if (picture[dx][dy] != color) continue;
			picture[dx][dy] = 0;
			q.push({ dx, dy, size += 1 });
		}
	}
	return picture;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	vector<int> answer;
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	max_size = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] == 0) continue;
			number_of_area++;
			picture = ff(picture[i][j], i, j, m, n, picture);
		}
	}

	max_size_of_one_area = max_size;
	answer.push_back(number_of_area);
	answer.push_back(max_size_of_one_area);
	return answer;
}

int main() {
	int m = 6; int n = 4;
	vector<vector<int>> picture = { {1, 1, 1, 0},{1, 1, 1, 0},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1} };
	vector<int> answer = solution(m, n, picture);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
}