#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;
	vector<string> dic;

	for (char i = 'A'; i <= 'Z'; i++)
		dic.push_back(string(1, i));

	while (msg.length() != 0) {
		for (int i = msg.length(); i >= 1; i--) {
			string word = msg.substr(0, i); //0부터 i글자
			auto idx = find(dic.begin(), dic.end(), word);
			if (idx == dic.end()) continue; //사전에 존재x
			answer.push_back(idx - dic.begin() + 1); //사전의 index 넣기
			msg.erase(0, i);
			if (msg.length() == 0) break;
			dic.push_back(word + msg[0]);
			break;
		}
	}
	return answer;
}

int main() {
	string msg = "KAKAO";
	vector<int> answer = solution(msg);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
}