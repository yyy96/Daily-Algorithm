#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int connect;
int cnt = 0;
int used[101];
queue<int> q;
vector<vector<int>> computer(101);

void fun() {
	while (!q.empty()) {
		int now = q.front();
		if(now!=1) cnt++;
		q.pop();

		for (int i = 0; i < computer[now].size(); i++) {
			int next = computer[now][i];
			if (used[next] == 1) continue;
			used[next] = 1;
			q.push(next);
		}
	}
}

void init() {
	cin >> n;
	cin >> connect;

	for (int i = 0; i < connect; i++) {
		int to, from;
		cin >> to >> from;
		computer[to].push_back(from);
		computer[from].push_back(to);
	}

	q.push(1);
	used[1] = 1;
}

int main() {
	init();
	fun();
	cout << cnt;
	return 0;
}