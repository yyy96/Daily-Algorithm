#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Node {
	int next;
	int weight;
};
vector<vector<int>> map;
vector<vector<Node>> node(10);
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int used[10];
int n;
int minweight = 21e8;

void dfs(int lev, int start, int now, int sum) {
	if (lev == n) {
		if (map[now][start] != 0) {
			sum += map[now][start];
			minweight = min(minweight, sum);
		}
		return;
	}

	for (int i = 0; i < node[now].size(); i++) {
		int next = node[now][i].next;
		if (used[next] == 1) continue;
		used[next] = 1;
		dfs(lev + 1, start, next, sum + node[now][i].weight);
		used[next] = 0;
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) continue;
			node[i].push_back({ j, map[i][j] });
		}
	}
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> line;
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			line.push_back(num);
		}
		map.push_back(line);
	}
}

int main() {
	input();
	init();

	for (int i = 0; i < n; i++) {
		used[i] = 1;
		dfs(1, i, i, 0);
		used[i] = 0;
	}

	cout << minweight;

	return 0;
}