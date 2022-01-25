#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int total_push = 0;
	int priority = 0;
	int n = progresses.size();
	vector<int> day(n);

	while (1) {
		for (int i = 0; i < n; i++) { //i=�Ϸ�
			if (progresses[i] >= 100) continue;
			progresses[i] += speeds[i];
		}

		if (progresses[priority] >= 100) { //���� ������ 100�� ä��������
			int cnt = 0;
			for (int i = priority; i < n; i++) {
				if (progresses[i] >= 100) { //�̹� ���� �͵��� �Բ� ����
					cnt++;
					continue;
				}
				priority = i; //���� �غ� �ȵȰ� ���� �켱����
				break;
			}
			answer.push_back(cnt);
			total_push += cnt;
		}
		if (total_push == n) break;
	}
	return answer;
}

int main() {
	vector<int> progresses = { 93,30,55 }; //�����Ǿ���ϴ� �������(����), �۾� ����(��)
	vector<int> speeds = { 1,30,5 };       //�����Ǿ���ϴ� �������(����), �۾� �ӵ�(��)
	vector<int> answer = solution(progresses, speeds);

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i];
	return 0;
}