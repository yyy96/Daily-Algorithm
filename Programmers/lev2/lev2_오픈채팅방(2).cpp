#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <sstream>
#include <unordered_map>
using namespace std;

unordered_map<string, string> user;

vector<string> solution(vector<string> record) {
	vector<string> answer;

	//id(key)-�г���(value) Hash ����Ͽ� ��üȭ
	for (int i = 0; i < record.size(); i++) {
		string message, id, nickname;
		stringstream stream(record[i]); //stringstream �� ���Ͽ� split
		stream >> message;
		if (message == "Leave") continue;
		stream >> id >> nickname;
		user[id] = nickname;
	}

	for (int i = 0; i < record.size(); i++) {
		string message, id, nickname;
		stringstream stream(record[i]);
		stream >> message >> id;
		
		if (message == "Enter") {
			answer.push_back(user[id] + "���� ���Խ��ϴ�.");
		}
		else if (message == "Leave") {
			answer.push_back(user[id] + "���� �������ϴ�.");
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
		cout << answer[i] << ",";

	return 0;
}