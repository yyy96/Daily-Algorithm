#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define N 32001
using namespace std;

int n, m;
vector<vector<int>> seat(N);
int degree[N] = { 0, }; //내 앞에 몇 명(간선)이 있는지

void topology() {
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) //내 앞에 서는 사람이 없는 경우
			q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		cout << now << " ";

		for (int next : seat[now]) {
			degree[next]--;
			if (degree[next] == 0)
				q.push(next);
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		seat[a].push_back(b); //a뒤에 b가 서야한다.
		degree[b]++; //b의 간선이 추가된다.
	}

	topology();

	return 0;
}
