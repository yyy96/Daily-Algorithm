#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;

//효율성 시간초과 
bool checkCondition(vector<string> conditions, vector<string> info) {
	for (int i = 0; i < 4; i++) {
		if (conditions[i] == "-") continue;
		if (conditions[i] != info[i]) return false;
	}
	return true;
}

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	string lan, job, career, food, score, X;

	for (int q = 0; q < query.size(); q++) {
		int cnt = 0;
		stringstream ssq(query[q]);
		ssq >> lan >> X >> job >> X >> career >> X >> food >> score;
		vector<string> conditions = { lan, job, career, food, score };

		for (int i = 0; i < info.size(); i++) {
			stringstream ssi(info[i]);
			ssi >> lan >> job >> career >> food >> score;
			vector<string> infos = { lan, job, career, food, score };

			if (stoi(conditions[4]) > stoi(infos[4])) continue;
			if (checkCondition(conditions, infos)) cnt++;
		}
		answer.push_back(cnt);
	}
	return answer;
}

int main() {
	//언어+" "+직군+" "+경력+" "+음식
	vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
	vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
	vector<int> answer = solution(info, query);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
}