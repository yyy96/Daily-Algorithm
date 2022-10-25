#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 300001
using namespace std;

struct Node {
	int now, lev;
};
int n, m, k, x; //k:목표거리, x:출발도시
vector<vector<int>> city(MAX);
vector<int> result;

bool operator<(Node b, Node a) {
	return a.lev < b.lev;
}

void dj() {
	priority_queue<Node> q;
	bool visited[MAX] = { false, };
	q.push({ x, 0 });

	while (!q.empty()) {
		int now = q.top().now;
		int lev = q.top().lev;
		q.pop();

		if (visited[now]) continue;
		visited[now] = true;

		//주의 : visited 다음에 확인해줘야 함
		if (lev > k) continue;
		if (lev == k) {
			result.push_back(now);
			continue;
		}

		for (int i = 0; i < city[now].size(); i++) {
			int next = city[now][i];
			q.push({ next, lev + 1 });
		}
	}
}

int main()
{
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		city[a].push_back(b);
	}
	dj();

	if (result.empty()) cout << "-1";
	else {
		sort(result.begin(), result.end());
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << "\n";
	}
	return 0;
}
