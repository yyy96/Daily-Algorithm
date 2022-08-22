#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 103 //주변에 테두리를 해줄꺼면 MAX도 100이 아니라 여유분이 필요함.
using namespace std;

struct Node {
	int x, y;
};
int T;
int n, m;
char map[MAX][MAX];
int keys[30] = { 0, }; //A ~ Z
int direct[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

void init() {
	cin >> n >> m;
	//테두리는 여백을 주고, 테두리 안쪽부터 map 정보를 채워넣는다
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++) {
			map[i][j] = str[j - 1];
		}
	}

	string key;
	cin >> key;
	if (key == "0") return;
	for (int i = 0; i < key.length(); i++) {
		keys[key[i] - 'a'] = 1;
	}
}

int bfs() {
	int visted[MAX][MAX] = { 0, };
	queue<Node> q;
	vector<vector<Node>> doors(30); //경로중에서 못 열은 A 문을 n개 발견하였다.
	int cnt = 0;
	q.push({ 0,0 });
	visted[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + direct[i][0];
			int dy = y + direct[i][1];

			if (dx < 0 || dy < 0 || dx >= n + 2 || dy >= m + 2) continue;
			if (visted[dx][dy] == 1) continue;
			if (map[dx][dy] == '*') continue;
			if (map[dx][dy] == '$') cnt++;
			if (map[dx][dy] >= 'A' && map[dx][dy] <= 'Z') {
				int key = map[dx][dy] - 'A'; //이렇게 하면 DAT에서 범위를 줄일 수 있음
				if (keys[key] != 1) { //키가 없다면 못 열은 문을 기억해둔다.
					doors[key].push_back({ dx,dy });
					continue;
				}
			}
			if (map[dx][dy] >= 'a' && map[dx][dy] <= 'z') {
				int key = map[dx][dy] - 'a';
				keys[key] = 1;
				for (int j = 0; j < doors[key].size(); j++) { //키를 발견하면 못열었던 문들을 q에 갈 수 있도록 넣어준다.
					Node openDoor = doors[key][j];
					if (visted[openDoor.x][openDoor.y] == 1) continue;
					q.push(openDoor);
				}
			}
			visted[dx][dy] = 1;
			q.push({ dx,dy });
		}
	}
	return cnt;
}


int main() {
	cin >> T;
	while (T--) {
		init();
		cout << bfs() << endl;

		memset(map, 0, sizeof(map));
		memset(keys, 0, sizeof(keys));
	}
	return 0;
}