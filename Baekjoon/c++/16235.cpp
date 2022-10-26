#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#define N 11
using namespace std;

struct Tree {
	int x, y, age;
};
int n, m, k;
int map[N][N];
int Add[N][N];
int direct[8][2] = { {-1,0},{1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1} };
vector<Tree> tree;
queue<Tree> die;

bool compare(Tree a, Tree b) {
	if (a.x == b.x && a.y == b.y) return a.age < b.age;
	else return a.x < b.y;
}

//1. 나무 양분+=나이, 나이++ (어린 순서)
void spring() {
	//어린 순서대로.sort
	sort(tree.begin(), tree.end(), compare);

	for (int i = 0; i < tree.size(); i++) {
		Tree t = tree[i];
		if (map[t.x][t.y] >= t.age) {
			//map[t.x][t.y] -= t.age;
			tree[i].age++;
		}
		else {
			//나무 죽음
			die.push(t);
			tree.erase(tree.begin() + i);
			i--;
		}
	}
}

//2. 땅 양분+=죽은 나이/2
void summer() {
	while (!die.empty()) {
		Tree t = die.front();
		die.pop();
		map[t.x][t.y] += t.age / 2;
	}
}

//3. 번식(나이%5) 8방향(나이1)
void fall() {
	int treeCnt = tree.size();
	for (int i = 0; i < treeCnt; i++) {
		Tree t = tree[i];
		if (t.age % 5 != 0) continue;
		for (int i = 0; i < 8; i++) {
			int dx = t.x + direct[i][0];
			int dy = t.y + direct[i][1];
			if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
			tree.push_back({ dx,dy,1 });
		}
	}
}

//4. 땅 양분+= Add
void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			map[i][j] += Add[i][j];
	}
}

int solution() {
	for (int y = 0; y < k; y++) {
		spring();
		summer();
		fall();
		winter();
	}
	return tree.size();
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = 5;
			cin >> Add[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree.push_back({ x - 1,y - 1,z });
	}
	cout << solution();
}