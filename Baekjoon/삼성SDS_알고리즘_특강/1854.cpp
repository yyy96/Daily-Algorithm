#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Root {
	int time;
	int weight;
};
struct Node {
	int n;
	int weight;
};
vector<vector<Node>> node (1001);
Root result[1001];
int n, m, k; //k번째 경로 구하기. 도착지가 k 아님.


bool operator<(Node b, Node a) {
	return a.weight < b.weight;
}


void fun() {
	priority_queue<Node> q;
	q.push({ 1,0 });

	while (!q.empty()) {
		int now = q.top().n;
		int sum = q.top().weight;
		q.pop();

		result[now].time++;
		if (result[now].time > k) continue; //이걸 안해주면 메모리&시간초과
		if (result[now].time == k) {
			result[now].weight = sum;
		}
		
		for (int i = 0; i < node[now].size(); i++) {
			int next = node[now][i].n;
			int weight = node[now][i].weight;
			q.push({ next, sum + weight });
		}
	}
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
	}

	fun();

	for (int i = 1; i <= n; i++) {
		if (result[i].time < k) cout << "-1\n";
		else cout << result[i].weight << "\n";
	}
	return 0;
}