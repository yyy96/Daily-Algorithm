#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int cnt = 0;

void dfs(int lev, int sum, int target, vector<int> numbers) {
	/*
	//잘못된 가지치기의 예시
	if (sum > target)
		return;
	*/

	if (lev == numbers.size()) {
		if (sum == target)
			cnt++;
		return;
	}

	dfs(lev + 1, sum + numbers[lev], target, numbers);
	dfs(lev + 1, sum - numbers[lev], target, numbers);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	dfs(0, 0, target, numbers);
	answer = cnt;
	return answer;
}

int main() {
	vector<int> numbers = { 4,1,2,1 };
	int target = 4;
	cout << solution(numbers, target);
}