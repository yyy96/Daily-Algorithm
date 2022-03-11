#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
	int lev;
	string word;
};

bool check(string now, string next) {
	int dif = 0;
	for (int i = 0; i < now.length(); i++) {
		if (now[i] == next[i]) continue;
		dif++;
	}
	if (dif != 1) return false;
	return true;
}

int bfs(string begin, string target, vector<string> words) {
	queue<Node> q;
	q.push({ 0, begin });

	while (!q.empty()) {
		string now = q.front().word;
		int lev = q.front().lev;
		q.pop();

		if (lev > words.size())
			break;
		if (now == target)
			return lev;

		for (int i = 0; i < words.size(); i++) {
			string next = words[i];
			if (!check(now, next)) continue;
			q.push({lev+1, next});
		}
	}
	return -1;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;

	int have = 0;
	for (int i = 0; i < words.size(); i++) {
		if (words[i] == target) have++;
	}
	if (have == 0)
		return 0;

	answer = bfs(begin, target, words);
	return answer;
}

int main() {
	string begin = "hit";
	string target = "cog";
	vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
	cout << solution(begin, target, words);
	return 0;
}