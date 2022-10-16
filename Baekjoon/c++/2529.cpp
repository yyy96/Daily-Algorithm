#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int k;
char c[10];
int used[10];
string maxNum = "0";
string minNum = "9999999999";

void dfs(int lev, string num, int last) {
	if (lev == k) {
		if (maxNum < num) maxNum = num;
		if (minNum > num) minNum = num;
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (lev != -1 && c[lev] == '<' && last > i) continue;
		if (lev != -1 && c[lev] == '>' && last < i) continue;
		if (used[i] == 1) continue;
		used[i] = 1;
		dfs(lev + 1, num + to_string(i), i);
		used[i] = 0;
	}
}

int main()
{
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> c[i];

	dfs(-1, "", 0);
	cout << maxNum << endl;
	cout << minNum << endl;
	return 0;
}
