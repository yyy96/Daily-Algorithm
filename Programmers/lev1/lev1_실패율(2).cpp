#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Stage {
	int stage;
	double fail;
};

bool compare(Stage a, Stage b) {
	if (b.fail == a.fail)
		return a.stage < b.stage;
	return a.fail > b.fail;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<Stage> result;

	for (int stage = 1; stage <= N; stage++) {
		int players = 0;
		int failers = 0;
		for (int i = 0; i < stages.size(); i++) {
			if (stages[i] >= stage) players++;
			if (stages[i] == stage) failers++;
		}
		if (players == 0)
			result.push_back({ stage, 0 });
		else
			result.push_back({ stage, (double)failers / (double)players });
	}

	sort(result.begin(), result.end(), compare);
	for (int i = 0; i < N; i++) {
		answer.push_back(result[i].stage);
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