#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
int dp[101][101];
int minKB = 21e8;
int personKB;

void init() {
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		dp[a][b] = 1;
		dp[b][a] = 1;
	}
}

void fw() {
	//�÷��̵� ����
	for (int node = 1; node <= n; node++) { // ��� ������ �ѹ��� Ž���ϱ�.
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				//�� �� ���� ����̸� �н�
				if (i == j) continue;
				if (dp[i][node] == 0 || dp[node][j] == 0) continue;

				// ������Ʈ
				int new_distance = dp[i][node] + dp[node][j];
				if (dp[i][j] == 0)
					dp[i][j] = new_distance;
				else
					dp[i][j] = min(dp[i][j], new_distance);
			}
		}
	}
}

void result() {
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (minKB < sum) continue;
			sum += dp[i][j];
		}
		if (minKB > sum) {
			minKB = sum;
			personKB = i;
		}
	}
}

int main() {
	cin >> n >> m;

	init();
	fw();
	result();
	cout << personKB;

	return 0;
}