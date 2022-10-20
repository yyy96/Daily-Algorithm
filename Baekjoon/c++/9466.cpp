#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 100001
using namespace std;

int T, n;
int student[MAX];
int path[MAX];
bool used[MAX] = { false, };
bool team[MAX] = { false, };
int total;

void dfs(int lev, int start, int now) {
	if (student[now] == now) {
		if (lev == 0) {
			team[now] = true;
			total -= 1;
		}
		return;
	}
	if (lev != 0 && now == start) {
		total -= lev;
		for (int i = 0; i < lev; i++)
			team[path[i]] = true;
		return;
	}
	if (used[now] || team[now]) return;

	path[lev] = now;
	used[now] = true;
	dfs(lev + 1, start, student[now]);
	used[now] = false;
	path[lev] = 0;
}

int main()
{
	cin >> T;
	while (T--) {
		cin >> n;
		total = n;
		for (int i = 1; i <= n; i++)
			cin >> student[i];

		for (int i = 1; i <= n; i++) {
			if (team[i]) continue;
			dfs(0, i, i);
		}
		cout << total << endl;
		memset(team, false, n + 1);
	}
	return 0;
}
