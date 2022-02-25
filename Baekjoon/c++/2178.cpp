#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

struct Node {
	int x, y;
	int lev;
};
int direct[4][2] = {
	{-1,0},{1,0},{0,1},{0,-1}
};
queue<Node> q;
int arr[100][100];
int used[100][100];
int N, M;
int Min = 100000;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			arr[i][j] = str[j] - '0';
			used[i][j] = arr[i][j];
		}
	}

	q.push({ 0,0,1 });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int lev = q.front().lev;
		q.pop();

		if (x == N - 1 && y == M - 1) {
			if (lev < Min) Min = lev;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];

			if (dx < 0 || dy < 0 || dx >= N | dy >= M) continue;
			if (arr[dx][dy] != 1) continue;
			if (used[dx][dy] != 1) continue;
			used[dx][dy] = 0;

			q.push({ dx,dy,lev + 1 });
		}
	}

	cout << Min;

	return 0;
}