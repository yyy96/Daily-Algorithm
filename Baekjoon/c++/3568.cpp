#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string flip(string val) {
	string v = "";
	for (int i = val.length() - 1; i >= 0; i--) {
		if (val[i] != '*' && val[i] != '[' && val[i] != ']' && val[i] != '&') break;
		if (val[i] == '[') val[i] = ']';
		else if (val[i] == ']') val[i] = '[';
		v += val[i];
	}
	return v;
}

void solution(string str) {
	stringstream stream(str);
	string common;
	string val;

	stream >> common;
	while (stream >> val) {
		val.erase(val.size() - 1);
		if (val[val.length() - 1] == '*' || val[val.length() - 1] == ']' || val[val.length() - 1] == '&') {
			string v = flip(val);
			val = val.substr(0, val.length() - v.length());
			cout << common << v << " " << val << ";" << endl;
		}
		else
			cout << common << " " << val << ";" << endl;
	}
}

int main() {
	string str;
	//띄어쓰기 포함 문자열 받기
	getline(cin, str);
	solution(str);
	return 0;
}
