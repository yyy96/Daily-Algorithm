#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<string> number = { "zero","one","two","three","four","five","six","seven","eight","nine" };

int solution(string s) {
	int answer = 0;

	for (int i = 0; i < s.length(); i++) {
		if ('0' <= s[i] && s[i] <= '9') continue;
		for (int n = 0; n < 10; n++) {
			int idx = s.find(number[n]);
			if (idx == -1) continue;
			s.erase(idx, number[n].length());
			s.insert(idx, to_string(n));
		}
	}
	answer = stoi(s);
	return answer;
}

int main() {
	string s = "2three45sixseven";
	cout << solution(s);
	return 0;
}