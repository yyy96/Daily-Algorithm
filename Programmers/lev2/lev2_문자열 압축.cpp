#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int fun(string str, int cut) {
	vector<string> word;
	string newStr = "";

	//압축
	int i = 0;
	while (i < str.length()) {
		string w = str.substr(i, cut);
		word.push_back(w);
		i = i + cut;
	}

	//압축된 문자열 생성
	string before = "";
	for (int i = 0; i < word.size(); i++) {
		string now = word[i];
		if (before == now) continue;
		before = now;

		int cnt = 0;
		for (int j = i; j < word.size(); j++) {
			if (now == word[j]) cnt++;
			else break;
		}

		if (cnt > 1) {
			newStr += to_string(cnt) + now;
		}
		else {
			newStr += now;
		}
	}

	return newStr.length();
}

int solution(string s) {
	int answer = 21e8;
	for (int i = 1; i <= s.length(); i++) { //압축할 개수
		int len = fun(s, i);
		answer = min(answer, len);
	}
	return answer;
}

int main() {
	string s;
	cin >> s;
	int result = solution(s);
	cout << result;
	return 0;
}