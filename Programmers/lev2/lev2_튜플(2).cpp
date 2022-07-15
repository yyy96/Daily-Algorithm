#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

vector<int> solution(string s) {
	vector<int> answer;
	unordered_map<int, int> dat;

	string num;
	for (char i : s) {
		if ('0' <= i && i <= '9') {
			num += i;
			continue;
		}
		if (num.length()) {
			dat[stoi(num)]++;
			num.clear();
		}
	}

	vector<pair<int, int>> numes;
	for (auto i = dat.begin(); i != dat.end(); ++i) {
		numes.push_back({ i->first, i->second });
	}
	sort(numes.begin(), numes.end(), compare);

	for (auto i : numes)
		answer.push_back(i.first);
	return answer;
}

int main() {
	string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
	vector<int> answer = solution(s);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
}