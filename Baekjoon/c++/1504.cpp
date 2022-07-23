#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int n, w;
};
int n, e;
int v1, v2;
vector<vector<Node>> node(801);

bool operator<(Node b, Node a) {
	return a.w < b.w;
}

int bfs(int start, int end) {
	priority_queue<Node> q;
	int used[801] = { 0, };
	q.push({ start,0 });

	while (!q.empty()) {
		int n = q.top().n;
		int sum = q.top().w;
		q.pop();

		if (used[n] >= 10) continue;
		used[n]++;
		if (n == end) return sum;

		for (int i = 0; i < node[n].size(); i++) {
			Node next = node[n][i];
			q.push({ next.n, sum + next.w });
		}
	}
	return -1;
}

void init() {
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
		node[b].push_back({ a,c });
	}
	cin >> v1 >> v2;
}

int path(int s, int e) {
	int way1, way2, sum;

	way1 = bfs(1, s);
	if (way1 == -1) return -1;

	way2 = bfs(s, e);
	if (way2 == -1) return -1;

	sum = bfs(e, n);
	if (sum == -1) return -1;
	return sum + way1 + way2;
}

int main() {
	cin >> n >> e;
	if (e == 0) {
		cout << "-1";
		return 0;
	}
	init();

	int result1 = path(v1, v2); // 시작-v1-v2-끝
	int result2 = path(v2, v1); // 시작-v2-v1-끝

	if (result1 != -1 && result2 != -1) result1 = min(result1, result2);
	else result1 = max(result1, result2);

	cout << result1;
	return 0;
}