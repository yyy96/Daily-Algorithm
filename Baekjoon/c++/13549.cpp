#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100001
using namespace std;

struct Node {
	int n, time;
};
int n, k;

// �����̵��� ��쿡�� time(����,�ּҰ�)�� �� �����Ƿ� priority_queue
bool operator<(Node b, Node a) {
	return a.time < b.time;
}

int bfs() {
	vector<int> visted(MAX);
	priority_queue<Node> q;
	q.push({ n,0 });

	while (!q.empty()) {
		int sb = q.top().n;
		int time = q.top().time;
		q.pop();

		if (sb == k) return time;
		if (visted[sb] == 1) continue;
		visted[sb] = 1;

		int next = sb * 2;
		if (next < MAX) q.push({ next,time });

		next = sb + 1;
		if (next < MAX) q.push({ next,time + 1 });

		next = sb - 1;
		if (0 <= next) q.push({ next,time + 1 });
	}
	return -1;
}

int main()
{
	cin >> n >> k;
	cout << bfs();
	return 0;
}