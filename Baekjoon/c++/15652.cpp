#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int path[9];

void dfs(int lev, int start) {
	if (lev == m) {
		for (int i = 0; i < m; i++) cout << path[i] << " ";
		cout << endl;
		return;
	}

	for (int i = start; i <= n; i++) {
		path[lev] = i;
		dfs(lev + 1, i);
		path[lev] = 0;
	}
}

int main()
{
	cin >> n >> m;
	dfs(0, 1);
	return 0;
}
