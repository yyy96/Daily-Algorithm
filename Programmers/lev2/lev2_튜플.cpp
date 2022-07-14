#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compare(vector<int> a, vector<int> b) {
	return a.size() < b.size();
}

vector<int> split(string str) {
	vector<int> group;
	int s = 0;
	int e = 0;
	str += ',';
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ',') {
			e = i;
			string n = str.substr(s, e - s);
			s = i + 1;
			group.push_back(stoi(n));
		}
	}
	return group;
}

vector<int> solution(string str) {
	vector<int> answer;
	vector<vector<int>> groups;
	unordered_map<int, bool> used;

	int s, e;
	for (int i = 1; i < str.length() - 1; i++) {
		if (str[i] == '{') s = i;
		if (str[i] == '}') {
			e = i - 1;
			string g = str.substr(s + 1, e - s);
			groups.push_back(split(g));
		}
	}

	//원소 개수가 적은 순서대로 나열
	sort(groups.begin(), groups.end(), compare);
	for (int i = 0; i < groups.size(); i++) {
		vector<int> g = groups[i];
		for (int j = 0; j < g.size(); j++) {
			if (used[g[j]]) continue;
			used[g[j]] = true;
			answer.push_back(g[j]);
			break;
		}
	}
	return answer;
}

int main() {
	string str = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
	vector<int> answer = solution(str);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
}