#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#define MAX 51
using namespace std;

struct Node {
	int x, y;
	int lev;
	int key;
};
int n, m;
char map[MAX][MAX];
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
Node minsik;

int bfs() {
	int used[MAX][MAX][64] = { 0, }; //키를 지닌 상태에서 visted 했는가. key값은 000000 ~ 111111 이어서 64 size
	queue<Node> q;
	q.push(minsik);

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int lev = q.front().lev;
		int key = q.front().key;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
			if (used[dx][dy][key] == 1) continue;
			if (map[dx][dy] == '#') continue;
			if (map[dx][dy] == '1') return lev + 1;
			if (map[dx][dy] >= 'a'&& map[dx][dy] <= 'f') {
				int addKey = key | (1 << (map[dx][dy] - 'a')); // OR 연산자로 기존 key에 발견한 key를 더해줌
				if (used[dx][dy][addKey] == 1) continue;
				used[dx][dy][addKey] = 1;
				q.push({ dx,dy,lev + 1, addKey });
				continue;
			}
			if (map[dx][dy] >= 'A'&& map[dx][dy] <= 'F') {
				int haveKey = key & (1 << (map[dx][dy] - 'A')); // AND 연산자로 기존 key에 발견한 key의 비트가 1(존재)인지 확인.
				if (haveKey == 0) continue; //& 키를 발견하지 못하면 0
			}
			used[dx][dy][key] = 1;
			q.push({ dx,dy,lev + 1,key });
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j];
			if (str[j] == '0') {
				map[i][j] = '.';
				minsik = { i,j,0, 0 };
			}
		}
	}

	cout << bfs();
	return 0;
}