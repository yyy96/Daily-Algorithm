#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

struct Num {
	int n;
	int p; //pow
	int d; //double
	bool m; //plus or minus
};
vector<Num> scores;

void setting(int score, char b, int d, bool m) {
	if (b == 'S') scores.push_back({ score, 1, d, m });
	else if (b == 'D') scores.push_back({ score, 2, d, m });
	else if (b == 'T') scores.push_back({ score, 3, d, m });
}

int cal() {
	int answer = 0;
	for (int i = 0; i < scores.size(); i++) {
		int score;
		if (scores[i].d) score = scores[i].d * pow(scores[i].n, scores[i].p);
		else score = pow(scores[i].n, scores[i].p);

		if (scores[i].m) answer += score;
		else answer -= score;
	}
	return answer;
}

int solution(string dartResult) {
	int answer = 0;
	string scoreStr = "";

	for (int i = 0; i < dartResult.length(); i++) {
		char c = dartResult[i];
		if ('0' <= c && c <= '9') {
			scoreStr += c;
			continue;
		}

		//보너스,옵션
		if (i != dartResult.length() && dartResult[i + 1] == '*') {
			if (scores.size() != 0) {
				int last = scores.size() - 1;
				scores[last].d += 2;
			}
			setting(stoi(scoreStr), c, 2, true);
			i++;
		}
		else if (i != dartResult.length() && dartResult[i + 1] == '#') {
			setting(stoi(scoreStr), c, 0, false);
			i++;
		}
		else
			setting(stoi(scoreStr), c, 0, true);

		scoreStr = "";
	}

	answer = cal();
	return answer;
}

int main() {
	//string dartResult = "1S2D*3T";
	string dartResult = "1S*2T*3S";
	cout << solution(dartResult);
	return 0;
}