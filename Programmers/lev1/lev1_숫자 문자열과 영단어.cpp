#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

string number = "";

bool checkWord(string str, int start, int end) {
	if (str == "zero") {
		number += "0";
		return true;
	}
	else if (str == "one") {
		number += "1";
		return true;
	}
	else if (str == "two") {
		number += "2";
		return true;
	}
	else if (str == "three") {
		number += "3";
		return true;
	}
	else if (str == "four") {
		number += "4";
		return true;
	}
	else if (str == "five") {
		number += "5";
		return true;
	}
	else if (str == "six") {
		number += "6";
		return true;
	}
	else if (str == "seven") {
		number += "7";
		return true;
	}
	else if (str == "eight") {
		number += "8";
		return true;
	}
	else if (str == "nine") {
		number += "9";
		return true;
	}
	return false;
}


void changeEnglish(string s, int start) {
	string str = "";
	for (int i = start; i < s.length(); i++) {
		if ('0' <= s[i] && s[i] <= '9') break;
		str += s[i];
		if (checkWord(str, start, i))
			start = i + 1;
	}
}

int solution(string s) {
	int answer = 0;

	for (int i = 0; i < s.length(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			number += s[i];
			continue;
		}
		changeEnglish(s, i);
	}
	answer = stoi(number);

	return answer;
}

int main() {

	string str = "23four5six7";
	cout << solution(str);

	return 0;
}