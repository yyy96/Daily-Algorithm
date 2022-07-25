#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define INIT 21e8
using namespace std;

int used[6] = { 0, }; //1*1,2*2,3*3,4*4,5*5 5���� ����
int paper = 0;        //�ٿ����� ĭ(1) ����
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

//dfs ����Ž�� Ǯ��
void dfs(int lev, int x, int y, vector<vector<int>> arr) {
	if (lev > result) return;
	//�Ź� ��Ž���� �� �ٿ����� Ȯ������ ����
	//���� �� ������ �� �ٿ��ٸ� return
	if (paper == 0) {
		result = min(lev, result);
		return;
	}

	//���ο� 1(x,y) ã��
	int dx = x; int dy = y;
	for (int i = x; i < 10; i++) {
		if (arr[dx][dy] == 1) break;
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 0) continue;
			dx = i; dy = j;
			break;
		}
	}

	//branch = 5���� ũ��
	for (int s = 5; s >= 1; s--) {
		if (used[s] == 5) continue;
		if (!check(dx, dy, s, arr)) continue;
		used[s]++;
		paper -= s * s;
		//���� ���󺹱��� �ʿ���� arr ��ſ� �־��ָ� ���������� ���Ӱ� �ݿ��ǰ�, return �Ǹ� �ٽ� ���� lev�� arr�� �ȴ�.
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