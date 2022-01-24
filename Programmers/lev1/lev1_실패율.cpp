#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Stage {
	int lev;
	double rate;
};
struct Status {
	int success;
	int fail;
};

bool comp(Stage A, Stage B) {
	if (A.rate > B.rate)
		return true;
	else if (A.rate < B.rate)
		return false;
	else
		return A.lev < B.lev;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<Status> status(N + 1);
	vector<Stage> result(N);

	//level init
	for (int i = 0; i < N; i++) {
		result[i].lev = i + 1;
	}

	//stage ��Ȳ�� ���� ����&���� count
	for (int i = 0; i < stages.size(); i++) {
		int now = stages[i] - 1;
		status[now].fail++;
		for (int j = 0; j < now; j++) {
			status[j].success++;
		}
	}

	//������ ���
	for (int i = 0; i < N; i++) {
		if (status[i].success == 0 && status[i].fail != 0) {
			result[i].rate = 100;
			continue;
		}
		else if (status[i].fail == 0) {
			result[i].rate = 0;
			continue;
		}
		result[i].rate = (double)status[i].fail / (double)status[i].success;
	}

	//������ ���� ���� ����
	sort(result.begin(), result.end(), comp);

	//�������� ���� ���ĵ� ���� ���
	for (int i = 0; i < N; i++) {
		answer.push_back(result[i].lev);
	}

	return answer;
}

int main() {
	int n = 5;
	vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
	vector<int> answer = solution(n, stages);

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
}