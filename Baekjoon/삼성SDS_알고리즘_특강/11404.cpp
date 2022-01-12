#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, m;
int arr[101][101] = { 0, };

void fun() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			arr[i][j] = INF;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (arr[a][b] > c) arr[a][b] = c;
		//�� ������ ������ �ٸ��� ����.
		//�ֳĸ� ���۵��� ������ �����ϴ� �뼱�� �ϳ��� �ƴ� �� �� �ִٰ� �������� �� ���� root ���� ���� �� ����
	}

	fun();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] >= INF) arr[i][j] = 0; //INF �� �۰� �ص� ����
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}