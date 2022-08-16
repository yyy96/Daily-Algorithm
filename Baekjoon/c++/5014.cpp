#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#define INT 21e8
using namespace std;

struct Elevator {
	int floor;
	int lev;
};
int F, S, G, U, D;
int result = INT;

void bfs() {
	unordered_map<int, int> visted;
	queue<Elevator> q;
	q.push({ S,0 });
	visted[S] = 1;

	if (S > G && D == 0) return;
	if (S < G && U == 0) return;

	while (!q.empty()) {
		int floor = q.front().floor;
		int lev = q.front().lev;
		q.pop();

		if (floor == G) {
			result = lev;
			return;
		}

		int next;
		next = floor + U;
		if (next <= F && visted[next] != 1) {
			q.push({ next, lev + 1 });
			visted[next] = 1;
		}
		next = floor - D;
		if (next > 0 && visted[next] != 1) {
			q.push({ next, lev + 1 });
			visted[next] = 1;
		}
	}
}

int main() {
	cin >> F >> S >> G >> U >> D;
	bfs();
	if (result == INT) cout << "use the stairs";
	else cout << result;
	return 0;
}