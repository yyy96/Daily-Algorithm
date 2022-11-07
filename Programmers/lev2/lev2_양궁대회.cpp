#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Score {
	int L = 0, A = 0;
};
Score score[11];
string result = "";
int maxScore = 0;
bool win = false;

void cal() {
	//점수 계산
	int lion = 0, apeach = 0;
	for (int i = 0; i <= 10; i++) {
		if (score[i].A != 0 && score[i].L <= score[i].A) apeach += i;
		if (score[i].L > score[i].A)  lion += i;
	}

	//둘의 점수 차이 확인 후, path 갱신(낮은 점수 순)
	int diff = lion - apeach;
	if (diff <= 0) return;
	if (lion > apeach && maxScore <= diff) {
		win = true;
		string path = "";
		for (int i = 0; i <= 10; i++)
			path += score[i].L + '0';
		if (maxScore == diff && result < path) result = path;
		if (maxScore == 0 || maxScore < diff) result = path;
		maxScore = diff;
	}
}

void dfs(int lev, int start, int n) {
	if (lev == n) {
		cal();
		return;
	}

	for (int i = start; i >= 0; i--) {
		score[i].L++;
		dfs(lev + 1, i, n);
		score[i].L--;
	}
}

vector<int> solution(int n, vector<int> info) {
	vector<int> answer;
	for (int i = 0; i < info.size(); i++) {
		score[10 - i].A = info[i];
	}
	dfs(0, 10, n);
	if (!win) return { -1 };
	for (int i = 10; i >= 0; i--)
		answer.push_back(result[i] - '0');
	return answer;
}

int main() {
	int n = 5;
	vector<int> info = { 2,1,1,1,0,0,0,0,0,0,0 };
	solution(n, info);
	return 0;
}