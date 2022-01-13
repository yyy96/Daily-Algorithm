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
vector<vector<Node>> party(1001);
vector<vector<Node>> home(1001);
int student[1001] = { 0, };

bool operator<(Node b, Node a) {
	return a.weight < b.weight;
}

void goParty() {
	int used[1001] = { 0, };
	priority_queue<Node> q;
	q.push({ x,0 });

	while (!q.empty()) {
		int now = q.top().n;
		int sum = q.top().weight;
		q.pop();

		if (used[now] == 1) continue;
		used[now] = 1;
		student[now] += sum;

		for (int i = 0; i < party[now].size(); i++) {
			q.push({ party[now][i].n, sum + party[now][i].weight });
		}
	}
}

void goHome() {
	int used[1001] = { 0, };
	priority_queue<Node> q;
	q.push({ x,0 });

	while (!q.empty()) {
		int now = q.top().n;
		int sum = q.top().weight;
		q.pop();

		if (used[now] == 1) continue;
		used[now] = 1;
		student[now] += sum;

		for (int i = 0; i < home[now].size(); i++) {
			q.push({ home[now][i].n, sum + home[now][i].weight });
		}
	}
}

int main() {
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		party[a].push_back({ b,c });
		home[b].push_back({ a,c });
	}

	goParty();
	goHome();

	int maxStudent = 0;
	for (int i = 1; i <= n; i++) {
		if (maxStudent < student[i]) maxStudent = student[i];
	}
	cout << maxStudent;

	return 0;
}