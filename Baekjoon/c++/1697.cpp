#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Node {
	int now;
	int time;
};
int used[100002] = { 0, };
queue<Node> q;
int n, k;

int fun() {
	while (!q.empty()) {
		int now = q.front().now;
		int time = q.front().time;
		if (now == k) return time;
		q.pop();

		int next;
		next = now * 2;
		if (next<=100000 && used[next] != 1) {
			used[next] = 1;
			q.push({ next, time + 1 });
		}
		next = now + 1;
		if (next <= 100000 && used[next] != 1) {
			used[next] = 1;
			q.push({ next, time + 1 });
		}
		next = now - 1;
		if (next >=0 && used[next] != 1) {
			used[next] = 1;
			q.push({ next, time + 1 });
		}
	}
	return -1;
}

int main() {
	cin >> n >> k;
	q.push({ n,0 });
	cout << fun();
	return 0;
}