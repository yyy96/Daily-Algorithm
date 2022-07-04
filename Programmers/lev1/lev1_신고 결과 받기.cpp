#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <sstream>
#include <algorithm>
using namespace std;

unordered_multimap<string, string> spam;
unordered_map<string, int> spamCnt;

//중복된 신고인지 검증
bool validateSpam(string id, string name) {
	auto key = spam.equal_range(id);
	for (auto i = key.first; i != key.second; ++i) {
		if (i->second == name) {
			return true;
		}
	}
	return false;
}

//신고 횟수가 k번 이상인지 체크
int countStop(string id, int k) {
	auto key = spam.equal_range(id);
	int cnt = 0;
	for (auto i = key.first; i != key.second; ++i) {
		if (spamCnt[i->second] >= k) {
			cnt++;
		}
	}
	return cnt;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;

	//신고
	int rs = report.size();
	for (int i = 0; i < rs; i++) {
		stringstream ss;
		string id, name;
		ss.str(report[i]);
		ss >> id >> name;
		//if 만약 이미 신고했다면 continue
		if (validateSpam(id, name)) continue;
		spam.insert({ id, name });
		spamCnt[name]++;
	}

	int is = id_list.size();
	for (int i = 0; i < is; i++) {
		string id = id_list[i];
		int cnt = countStop(id, k);
		answer.push_back(cnt);
	}

	return answer;
}

int main() {
	vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
	vector<string> report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
	int k = 2;

	vector<int> answer = solution(id_list, report, k);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}


	return 0;
}