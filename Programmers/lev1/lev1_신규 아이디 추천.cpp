#include <iostream>
#include <string>
#include <vector>

using namespace std;
string result_id;

void checkLength(string id) {
	int len = id.length();
	if (len >= 16) {
		id.erase(15, len - 15);
		if (id[15] == '.') id.erase(14, 1);
	}
	else if (len <= 2) {
		if (len == 0) {
			id += "a";
			len++;
		}
		if (len == 1) {
			id += id[len - 1];
			len++;
		}
		if (len == 2) {
			id += id[len - 1];
			len++;
		}
	}
	result_id = id;
}

void checkPriod(string id) {
	string str = "";
	int strIdx = 0;
	for (int i = 0; i < id.length(); i++) {
		if (strIdx != 0 && str[strIdx - 1] == '.' && id[i] == '.') continue;
		str += id[i];
		strIdx++;
	}

	if (str[0] == '.') {
		str.erase(0, 1);
		strIdx--;
	}
	if (str[strIdx - 1] == '.') {
		str.erase(strIdx - 1, 1);
	}

	result_id = str;
}

void exculdeWord(string id) {
	string str = "";
	for (int i = 0; i < id.length(); i++) {
		if ('a' <= id[i] && id[i] <= 'z')
			str += id[i];
		else if ('0' <= id[i] && id[i] <= '9')
			str += id[i];
		else if (id[i] == '-' || id[i] == '_' || id[i] == '.')
			str += id[i];
	}
	result_id = str;
}

void lowerCase(string id) {
	for (int i = 0; i < id.length(); i++) {
		if ('A' <= id[i] && id[i] <= 'Z')
			id[i] += 32;
	}
	result_id = id;
}

string solution(string new_id) {
	lowerCase(new_id);
	exculdeWord(result_id);
	checkPriod(result_id);
	checkLength(result_id);
	return result_id;
}

int main() {
	string new_id = "...abc...";
	cout << solution(new_id);
	return 0;
}