#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 42
using namespace std;

int n, m, k;
int total = 0;
int map[MAX][MAX] = { 0, };


void stick(vector<vector<int>> sticker, int r, int c, int sx, int sy) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			//만약 이미 붙여진 곳에 0 으로 덧씌워지는 것 주의
			map[sx + i][sy + j] += sticker[i][j];
		}
	}
}

bool check(vector<vector<int>> sticker) {
	//스티커가 회전하게되면 r,c가 달라지므로 전역변수로 두면 오류
	int r = sticker.size();
	int c = sticker[0].size();

	for (int i = 0; i <= n - r; i++) {
		for (int j = 0; j <= m - c; j++) {
			//시작점 정함
			bool flag = true;
			for (int x = 0; x < r; x++) {
				if (!flag) break;
				for (int y = 0; y < c; y++) {
					if (sticker[x][y] == 1 && map[i + x][j + y] == 1) {
						flag = false;
						break;
					}
				}
			}
			//붙일 수 있다면, 붙이고 true 리턴
			if (flag) {
				stick(sticker, r, c, i, j);
				return true;
			}
		}
	}
	return false;
}

vector<vector<int>> flip(vector<vector<int>> sticker) {
	vector<vector<int>> newsticker;

	//세로->가로 이중 for문 순서 주의
	for (int j = 0; j < sticker[0].size(); j++) {
		vector<int> line;
		for (int i = sticker.size() - 1; i >= 0; i--) {
			int can = sticker[i][j];
			line.push_back(can);
		}
		newsticker.push_back(line);
	}
	return newsticker;
}

int main() {
	cin >> n >> m >> k;

	while (k--) {
		int r, c;
		cin >> r >> c;
		vector<vector<int>> sticker;
		for (int i = 0; i < r; i++) {
			vector<int> line;
			for (int j = 0; j < c; j++) {
				int can;
				cin >> can;
				line.push_back(can);
			}
			sticker.push_back(line);
		}

		//1. 스티커를 붙인다
		//2. 못붙일 경우 회전하고 붙인다. (불가능하면 버린다)
		for (int i = 0; i <= 4; i++) {
			if (check(sticker)) break;
			sticker = flip(sticker);
		}
	}

	//스티커가 붙은 칸의 개수를 센다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) total++;
		}
	}
	cout << total;
	return 0;
}