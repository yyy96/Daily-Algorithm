#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int n;
	int weight;
};
int n, m, x;
vector<vector<Node>> node (1001);
int maxStudent = 0;

bool operator<(Node b, Node a) {
	return a.weight < b.weight;
}

int party(int start) {
	priority_queue<Node> q;
	int used[1001] = { 0, };
	q.push({ start,0 });

	int sum = 0;
	while (!q.empty()) {
		int now = q.top().n;
		sum = q.top().weight;
		q.pop();

		if (now == x) break;
		if (used[now] == 1) continue;
		used[now] = 1;

		for (int i = 0; i < node[now].size(); i++) {
			int next = node[now][i].n;
			int weight = node[now][i].weight;
			q.push({ next, sum + weight });
		}
	}
	return sum;
}

int home(int end) {
	priority_queue<Node> q; //이전 q가 empty() 해서 끝난게 아니라 x를 만나서 끝난거라 현재 q에 max 값들이 남아있음. (다익스트라 특징)
	int used[1001] = { 0, };
	q.push({ x,0 });

	int sum = 0;
	while (!q.empty()) {
		int now = q.top().n;
		sum = q.top().weight;
		q.pop();

		if (now == end) break;
		if (used[now] == 1) continue;
		used[now] = 1;

		for (int i = 0; i < node[now].size(); i++) {
			int next = node[now][i].n;
			int weight = node[now][i].weight;
			q.push({ next, sum + weight });
		}
	}
	return sum;
}

int main() {
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
	}

	for (int i = 1; i <= n; i++) {
		int distance = party(i) + home(i);
		if (maxStudent < distance)
			maxStudent = distance;
	}

	cout << maxStudent;

	return 0;
}