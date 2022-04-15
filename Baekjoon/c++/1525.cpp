#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;

struct Node {
	string now;
	int cnt;
};
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
string str = "";
string answer = "123456780";


int bfs() {
	queue<Node> q;
	unordered_map<string, int> used;
	q.push({ str, 0 });

	while (!q.empty()) {
		string now = q.front().now;
		int cnt = q.front().cnt;
		q.pop();

		if (now == answer)
			return cnt;

		//find zero
		int zero = now.find('0');
		int zeroX = zero / 3;
		int zeroY = zero % 3;

		for (int i = 0; i < 4; i++) {
			int dx = zeroX + direct[i][0];
			int dy = zeroY + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= 3 || dy >= 3) continue;

			//move
			string next = now;
			int moveIdx = (dx * 3) + dy;
			next[zero] = now[moveIdx];
			next[moveIdx] = '0';

			//cycle check
			if (used[next] == 1) continue;
			used[next] = 1;

			q.push({ next, cnt + 1 });
		}
	}

	return -1;
}

int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			char c;
			cin >> c;
			str += c;
		}
	}
	cout << bfs();
	return 0;
}