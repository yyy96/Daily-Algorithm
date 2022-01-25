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
		for (int i = 0; i < n; i++) { //i=하루
			if (progresses[i] >= 100) continue;
			progresses[i] += speeds[i];
		}

		if (progresses[priority] >= 100) { //배포 순서때 100이 채워졌으면
			int cnt = 0;
			for (int i = priority; i < n; i++) {
				if (progresses[i] >= 100) { //이미 끝난 것들은 함께 배포
					cnt++;
					continue;
				}
				priority = i; //배포 준비 안된게 다음 우선순위
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
	vector<int> progresses = { 93,30,55 }; //배포되어야하는 순서대로(정렬), 작업 진도(값)
	vector<int> speeds = { 1,30,5 };       //배포되어야하는 순서대로(정렬), 작업 속도(값)
	vector<int> answer = solution(progresses, speeds);

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i];
	return 0;
}