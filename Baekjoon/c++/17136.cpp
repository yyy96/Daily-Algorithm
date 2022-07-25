#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define INIT 21e8
using namespace std;

int used[6] = { 0, }; //1*1,2*2,3*3,4*4,5*5 5개씩 존재
int paper = 0;        //붙여야할 칸(1) 개수
int result = INIT;

bool check(int x, int y, int size, vector<vector<int>> arr) {
	if (x + size > 10 || y + size > 10) return false;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (i >= 10 || j >= 10) return false;
			if (arr[i][j] == 0) return false;
		}
	}
	return true;
}

vector<vector<int>> attach(int x, int y, int size, vector<vector<int>> arr) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			arr[i][j] = 0;
		}
	}
	return arr;
}

//dfs 완전탐색 풀이
void dfs(int lev, int x, int y, vector<vector<int>> arr) {
	if (lev > result) return;
	//매번 완탐으로 다 붙였는지 확인하지 말고
	//만약 그 공간을 다 붙였다면 return
	if (paper == 0) {
		result = min(lev, result);
		return;
	}

	//새로운 1(x,y) 찾기
	int dx = x; int dy = y;
	for (int i = x; i < 10; i++) {
		if (arr[dx][dy] == 1) break;
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 0) continue;
			dx = i; dy = j;
			break;
		}
	}

	//branch = 5종류 크기
	for (int s = 5; s >= 1; s--) {
		if (used[s] == 5) continue;
		if (!check(dx, dy, s, arr)) continue;
		used[s]++;
		paper -= s * s;
		//종이 원상복귀할 필요없이 arr 대신에 넣어주면 다음꺼에서 새롭게 반영되고, return 되면 다시 현재 lev의 arr가 된다.
		dfs(lev + 1, dx, dy, attach(dx, dy, s, arr));
		paper += s * s;
		used[s]--;
	}
}

int main() {
	vector<vector<int>> arr;

	for (int i = 0; i < 10; i++) {
		vector<int> line;
		for (int j = 0; j < 10; j++) {
			int n;
			cin >> n;
			if (n == 1) paper++;
			line.push_back(n);
		}
		arr.push_back(line);
	}

	dfs(0, 0, 0, arr);
	if (result == INIT) result = -1;
	cout << result;
	return 0;
}