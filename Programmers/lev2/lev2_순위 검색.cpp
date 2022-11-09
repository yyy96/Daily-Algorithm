#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string, vector<int>> scores;
string infoes[4];
string score;

//해당 조건들에 대한 조합 (사용,무관)
void dfs(int lev, int score, string info) {
	if (lev == 4) {
		scores[info].push_back(score);
		return;
	}
	dfs(lev + 1, score, info + infoes[lev]);
	dfs(lev + 1, score, info + '-');
}

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;

	//info split
	for (int i = 0; i < info.size(); i++) {
		stringstream ss(info[i]);
		ss >> infoes[0] >> infoes[1] >> infoes[2] >> infoes[3] >> score;
		dfs(0, stoi(score), "");
	}

	//각 key에 해당하는 vector 정렬
	for (auto i = scores.begin(); i != scores.end(); ++i)
		sort(i->second.begin(), i->second.end());

	//query에 해당하는 info 찾기
	for (int i = 0; i < query.size(); i++) {
		stringstream ss(query[i]);
		string AND;
		ss >> infoes[0] >> AND >> infoes[1] >> AND >> infoes[2] >> AND >> infoes[3] >> score;
		
		string key = infoes[0] + infoes[1] + infoes[2] + infoes[3];
		if (scores.find(key) != scores.end()) {
			auto lowIdx = lower_bound(scores[key].begin(), scores[key].end(), stoi(score));
			answer.push_back(scores[key].size() - (lowIdx - scores[key].begin()));
		}
		else
			answer.push_back(0);
	}
	return answer;
}

int main() {
	vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
	vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
	vector<int> answer = solution(info, query);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
}