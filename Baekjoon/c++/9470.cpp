#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define M 1001
using namespace std;

struct Node {
	int strahler; //순서
	int cnt;
};
int T;
int k, m, p;

int topology() {
	vector<vector<int>> node(m + 1);
	int degree[M] = { 0, };
	Node result[M] = { 0, };
	queue<int> q;
	int ﻿Strahler = 0;

	//init
	for (int i = 0; i < p; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		degree[b]++;
	}

	//시작 지점 넣어줌
	for (int i = 1; i <= m; i++) {
		if (degree[i] == 0) {
			result[i] = { 1,1 }; //{lev, n} lev강이 n번 들어왔다.
			q.push(i);
		}
	}

	//n개의 노드를 방문해야한다.
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		﻿Strahler = max(﻿Strahler, result[now].strahler);

		for (int next : node[now]) {
			degree[next]--; //간선 지워주기

			if (result[next].strahler == result[now].strahler)
				result[next].cnt++;
			if (result[next].strahler < result[now].strahler)
				result[next] = { result[now].strahler, 1 };

			if (degree[next] == 0) {
				if (result[next].cnt >= 2) result[next].strahler++;
				q.push(next);
			}
		}
	}
	return ﻿Strahler;
}

int main() {
	cin >> T;

	while (T--) {
		cin >> k >> m >> p;
		cout << k << " " << topology() << endl;
	}

	return 0;
}