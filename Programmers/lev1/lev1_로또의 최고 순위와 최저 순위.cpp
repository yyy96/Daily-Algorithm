#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

using namespace std;

int grade(int cnt) {
	if (cnt == 6) return 1;
	else if (cnt == 5) return 2;
	else if (cnt == 4) return 3;
	else if (cnt == 3) return 4;
	else if (cnt == 2) return 5;
	else return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;

	int zero = 0;
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		if (lottos[i] == 0) {
			zero++;
			continue;
		}
		for (int j = 0; j < 6; j++) {
			if (lottos[i] == win_nums[j])
				cnt++;
		}
	}

	int wrose = grade(cnt);
	int best = grade(cnt + zero);
	answer = { best,wrose };
	return answer;
}

int main() {
	vector<int> lottos = { 44, 1, 0, 0, 31, 25 };
	vector<int> win_nums = { 31, 10, 45, 1, 6, 19 };
	vector<int> result = solution(lottos, win_nums);
	cout << "["<< result[0] <<","<< result[1]<<"]";
	return 0;
}