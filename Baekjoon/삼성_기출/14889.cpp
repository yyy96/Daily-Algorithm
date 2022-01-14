#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n;
int team[21][21] = { 0, };
int path[11];
int used[21];
int total = 0;
int Min = 21e6;

void cal() {
	int sum1 = 0;
	int sum2 = 0;
	int path2[11];

	int t = 0;
	for (int i = 0; i < n; i++) {
		if (used[i] == 1) continue;
		path2[t] = i;
		t++;
	}

	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			if (i == j) continue;
			sum1 += team[path[i]][path[j]];
			sum2 += team[path2[i]][path2[j]];
		}
	}

	int gap = abs(sum1 - sum2);
	if (gap < Min) Min = gap;
}

void fun(int lev, int start) {
	// 절반만 해주고, start 를 해줘야 시간초과가 안난다
	// 어차피 나머지 절반은 남은 사람들이니까 굳이 나열 순서를 해줄 필요가 없다
	// 절반만 뽑게되면 그 절반 안에서는 1,2,3 을 뽑으면 3,1,2 와 동일한거니까 start 를 해줘야한다.
	// 절반을 안뽑았을시엔 1,3,4,2 & 1,4,2,3 이 다른거니까 순서가 중요해질 수 있다
	if (lev == n/2) {
		cal();
		return;
	}

	for (int i = start; i < n; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path[lev] = i;
		fun(lev + 1, i+1);
		path[lev] = 0;
		used[i] = 0;
	}
}


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> team[i][j];
			total += team[i][j];
		}
	}

	fun(0,0);
	cout << Min;

	return 0;
}