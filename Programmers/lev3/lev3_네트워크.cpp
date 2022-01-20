#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int node[201] = { 0, };

//bfs ���ؼ� ����� ���� ��� 1üũ. (MST ��� �ƴ�)
void bfs(vector<vector<int>> com, int n) {
	queue<int> q;
	q.push(n);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < com[now].size(); i++) {
			int next = com[now][i];
			if (node[next] == 1) continue;
			node[next] = 1;
			q.push(next);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	vector<vector<int>> com(n);

	//init
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (computers[i][j] == 0 || i==j ) continue;
			com[i].push_back(j);
		}
	}

	//���� Ȯ��
	for (int i = 0; i < n; i++) {
		if (node[i] == 1) continue;
		bfs(com, i);
		answer++;
	}

	return answer;
}

int main() {
	int n = 3;
	vector<vector<int>> computers = {
		{1,1,0},{1,1,0},{0,0,1}
	};
	cout << solution(n, computers);
	return 0;
}