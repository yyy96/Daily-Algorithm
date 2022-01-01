#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int n;
	int weight;
};
int v, e;
int k;
vector<vector<Node>> node(20001);
vector<int> Min(20001);
priority_queue<Node> q;

bool operator<(Node B, Node A) {
	return A.weight < B.weight;
}

void fun() {
	vector<int> used(v+1);
	q.push({ k, 0 });

	while (!q.empty()) {
		int now = q.top().n;
		int weight = q.top().weight;
		q.pop();

		if (used[now] == 1) continue; //for���� used�� ������ �� ���� weight �����̶� �ȳ־����� ��
		used[now] = 1;
		Min[now] = weight;

		for (int i = 0; i < node[now].size(); i++) {
			Node next = node[now][i];
			q.push({ next.n, weight + next.weight });
		}
	}
}

int main() {
	cin >> v >> e;
	cin >> k;
	for (int i = 0; i < e; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		node[s].push_back({ e,w });
	}

	fun();

	for (int i = 1; i <= v; i++) {
		if (i!=k && Min[i] == 0)
			cout << "INF" << "\n"; //�̰� endl �� �ϸ� �ð��ʰ� �߻�
		else
			cout << Min[i] << "\n";
	}

	return 0;
}