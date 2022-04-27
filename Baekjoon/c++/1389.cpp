#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
	int n;
	int lev;
};
int n, m;
vector<vector<int>> node(101);
int kb_min = 21e8;
int kb_person;

bool operator<(Node b, Node a) {
	return a.lev < b.lev;
}

void bfs(int start) {
	int used[101] = { 0, };
	priority_queue<Node> q;
	q.push({ start, 0 });
	int kb_sum = 0;

	while (!q.empty()) {
		int n = q.top().n;
		int lev = q.top().lev;
		q.pop();

		if (used[n] == 1) continue;
		used[n] = 1;
		kb_sum += lev;

		for (int i = 0; i < node[n].size(); i++) {
			int next = node[n][i];
			q.push({ next, lev + 1 });
		}
	}

	//결과 업데이트
	if (kb_min > kb_sum) {
		kb_min = kb_sum;
		kb_person = start;
	}
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	//다익스트라
	for (int i = 1; i <= n; i++) {
		bfs(i);
	}
	cout << kb_person;

	return 0;
}