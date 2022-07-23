#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int x, y;
	int sum;
};
int n;
int map[126][126];
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

bool operator<(Node b, Node a) {
	return a.sum < b.sum;
}

int bfs() {
	//더 느린 길이 최소 값일 수 있기 때문에 다익스트라
	priority_queue<Node> q;
	int used[126][126] = { 0, };
	q.push({ 0,0, map[0][0] });

	while (!q.empty()) {
		int x = q.top().x;
		int y = q.top().y;
		int sum = q.top().sum;
		q.pop();

		//더 느린 길이 최소 값일 수 있는데, 미리 visted 처리 해버리면 못가니까
		//하지만 여기서 체크하는건 이미 정렬되서 최소인 상태라 visted 체크
		if (used[x][y] == 1) continue;
		used[x][y] = 1;
		if (x == n - 1 && y == n - 1)
			return sum;

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
			q.push({ dx,dy, sum + map[dx][dy] });
		}
	}
	return -1;
}

int main() {
	int idx = 1;
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cin >> map[i][j];
		}
		cout << "Problem " << idx << " : " << bfs() << endl;
		idx++;
	}
	return 0;
}