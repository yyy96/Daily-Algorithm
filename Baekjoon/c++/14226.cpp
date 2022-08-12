#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define Max 2000
using namespace std;

struct Emoji {
	int monitor;
	int clipboard;
	int time;
};
int n;

int bfs() {
	queue<Emoji> q;
	//화면에 a개의 이모티콘이 있고, 클립보드에 b개의 이모티콘이 있는 상태 를 이미 방문했는가.
	bool used[Max][Max];
	q.push({ 1, 0, 0 });

	while (!q.empty()) {
		int monitor = q.front().monitor;
		int clipboard = q.front().clipboard;
		int time = q.front().time;
		q.pop();

		if (monitor == n) return time;
		if (used[monitor][clipboard]) continue;
		used[monitor][clipboard] = true;


		q.push({ monitor, monitor, time + 1 });
		if (clipboard != 0 && Max > monitor + clipboard) q.push({ monitor + clipboard, clipboard, time + 1 });
		if (monitor > 0) q.push({ monitor - 1, clipboard, time + 1 });
	}
	return -1;
}

int main() {
	cin >> n;
	cout << bfs();
	return 0;
}