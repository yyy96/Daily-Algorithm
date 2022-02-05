#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

enum dir {
	w,l,c
};
struct Node {
	int x, y;
};
struct Pipe {
	Node start;
	Node end;
	int dir;
};
int n;
int arr[17][17];
int used[17][17];
queue<Pipe> q;

void pushPipe(Node newStart, Node newEnd, int newDir) {
	if (newEnd.x < 0 || newEnd.y < 0 || newEnd.x >= n || newEnd.y >= n) return;
	if (arr[newEnd.x][newEnd.y] == 1) return;
	if (used[newEnd.x][newEnd.y] == 1) return;
	used[newEnd.x][newEnd.y] == 1;
	q.push({ newStart, newEnd, newDir });
}

void goWidth(Node start, Node end) {
	Node newStart = end;
	Node newEnd = { end.x, end.y + 1 };
	int newDir = w;

	pushPipe(newStart, newEnd, newDir);
}

void goLength(Node start, Node end) {
	Node newStart = end;
	Node newEnd = { end.x+1, end.y };
	int newDir = l;

	pushPipe(newStart, newEnd, newDir);
}

void goCross(Node start, Node end) {
	Node newStart = end;
	Node newEnd = { end.x + 1, end.y + 1 };
	int newDir = c;

	if (arr[newEnd.x][newEnd.y] == 1 || arr[newEnd.x-1][newEnd.y]==1 || arr[newEnd.x][newEnd.y-1]==1) return;
	pushPipe(newStart, newEnd, newDir);
}

int fun() {
	int cnt = 0;
	q.push({ { 0,0 }, { 0,1 }, w });

	while (!q.empty()) {
		Node start = q.front().start;
		Node end = q.front().end;
		int dir = q.front().dir;
		q.pop();

		if (end.x == n - 1 && end.y == n - 1)
			cnt++;

		if (dir == w) {
			goWidth(start, end);
			goCross(start, end);
		}
		else if (dir == l) {
			goLength(start, end);
			goCross(start, end);
		}
		else if (dir == c) {
			goWidth(start, end);
			goLength(start, end);
			goCross(start, end);
		}
	}

	return cnt;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	cout << fun();

	return 0;
}