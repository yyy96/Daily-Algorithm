#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	long long n;
	int cnt;
};
long long A, B;

int bfs() {
	queue<Node> q;
	q.push({ A,1 });

	while (!q.empty()) {
		long long n = q.front().n;
		int cnt = q.front().cnt;
		q.pop();

		if (n > B) continue;
		if (n == B) return cnt;

		q.push({ n * 2, cnt + 1 });
		q.push({ n * 10 + 1 , cnt + 1 });
	}
	return -1;
}

int main()
{
	cin >> A >> B;
	cout << bfs();
	return 0;
}
