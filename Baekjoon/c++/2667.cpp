#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int x, y;
};
int n;
int arr[25][25];
int used[25][25];
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
vector<int> danziCnt;
queue<Node> q;
int danzi = 0;

int fun() {
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
			if (arr[dx][dy] == 0) continue;
			if (used[dx][dy] == 1) continue;
			used[dx][dy] = 1;
			q.push({ dx,dy });
		}
	}
	return cnt;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < n; j++) {
			arr[i][j] = line[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (used[i][j] == 1) continue;
			if (arr[i][j] == 1) {
				danzi++;
				q.push({ i,j });
				used[i][j] = 1;
				int cnt = fun();
				danziCnt.push_back(cnt);
			}
		}
	}

	sort(danziCnt.begin(), danziCnt.end());
	cout << danzi << endl;
	for (int i = 0; i < danzi; i++)
		cout << danziCnt[i] << endl;

	return 0;
}