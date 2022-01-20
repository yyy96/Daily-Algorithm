#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string> split(string str, char delimiter);
unordered_map<string, string> user;

//split 구현
vector<string> split(string input, char delimiter) {
	vector<string> answer;
	stringstream ss(input);
	string temp;
	while (getline(ss, temp, delimiter)) {
		answer.push_back(temp);
	}
	return answer;
}

vector<string> solution(vector<string> record) {
	vector<string> answer;

	//id(key)-닉네임(value) Hash 사용하여 일체화
	for (int i = 0; i < record.size(); i++) {
		vector<string> message = split(record[i], ' ');
		if (message[0] == "Leave") continue;
		user[message[1]] = message[2];
	}

	for (int i = 0; i < record.size(); i++) {
		vector<string> message = split(record[i], ' ');
		
		if (message[0] == "Enter") {
			answer.push_back(user[message[1]] + "님이 들어왔습니다.");
		}
		else if (message[0] == "Leave") {
			answer.push_back(user[message[1]] + "님이 나갔습니다.");
		}
	}
	return answer;
}

int main() {
	vector<string> record = {
		"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"
	};

	vector<string> answer = solution(record);

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;

	return 0;
}