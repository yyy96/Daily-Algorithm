#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

string kfriends = "ACFJMNRT";
int used[9];
char path[9];
int cnt = 0;

bool position(vector<string> data) {
	for (int i = 0; i < data.size(); i++) {
		//1. 사람 찾기
		int c1 = 0;
		int c2 = 0;
		for (int c = 0; c < 8; c++) {
			if (path[c] == data[i][0]) c1 = c;
			if (path[c] == data[i][2]) c2 = c;
		}

		//2. 간격 확인
		int kan = abs(c1 - c2) - 1;
		if (data[i][3] == '=') {
			if (kan != data[i][4] - '0') return false;
		}
		if (data[i][3] == '>') {
			if (kan <= data[i][4] - '0') return false;
		}
		if (data[i][3] == '<') {
			if (kan >= data[i][4] - '0') return false;
		}
	}
	return true;
}

//순열
void dfs(int lev, vector<string> data) {
	if (lev == 8) {
		if (position(data)) cnt++;
		return;
	}

	for (int i = 0; i < 8; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path[lev] = kfriends[i];
		dfs(lev + 1, data);
		path[lev] = 0;
		used[i] = 0;
	}
}

int solution(int n, vector<string> data) {
	int answer = 0;
	dfs(0, data);
	return cnt;
}

int main() {
	int n = 2;
	vector<string> data = { "N~F=0", "R~T>2" };
	cout << solution(n, data);
	return 0;
}