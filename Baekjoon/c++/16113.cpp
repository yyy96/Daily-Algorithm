#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string s;
vector<string> lines;

string solution() {
	string number = "";
	for (int i = 0; i < n; i++) {
		if (lines[0][i] == '#' && lines[1][i] == '#' && lines[2][i] == '#' && lines[3][i] == '#' && lines[4][i] == '#') { //0,1,6,8
			if (i + 1 == n || lines[0][i + 1] == '.' && lines[1][i + 1] == '.' && lines[2][i + 1] == '.' && lines[3][i + 1] == '.' && lines[4][i + 1] == '.') {
				number += "1";
				continue;
			}
			else if (lines[0][i + 1] == '#' && lines[1][i + 1] == '.' && lines[2][i + 1] == '.' && lines[3][i + 1] == '.' && lines[4][i + 1] == '#') number += "0";
			else if (lines[0][i + 2] == '#' && lines[1][i + 2] == '.' && lines[2][i + 2] == '#' && lines[3][i + 2] == '#' && lines[4][i + 2] == '#') number += "6";
			else if (lines[0][i + 2] == '#' && lines[1][i + 2] == '#' && lines[2][i + 2] == '#' && lines[3][i + 2] == '#' && lines[4][i + 2] == '#') number += "8";
		}
		else if (lines[0][i] == '#' && lines[1][i] == '#' && lines[2][i] == '#' && lines[3][i] == '.' && lines[4][i] == '#') { //5,9
			if (lines[0][i + 2] == '#' && lines[1][i + 2] == '.' && lines[2][i + 2] == '#' && lines[3][i + 2] == '#' && lines[4][i + 2] == '#') number += "5";
			if (lines[0][i + 2] == '#' && lines[1][i + 2] == '#' && lines[2][i + 2] == '#' && lines[3][i + 2] == '#' && lines[4][i + 2] == '#') number += "9";
		}
		else if (lines[0][i] == '#' && lines[1][i] == '.' && lines[2][i] == '#' && lines[3][i] == '#' && lines[4][i] == '#') number += "2";
		else if (lines[0][i] == '#' && lines[1][i] == '.' && lines[2][i] == '#' && lines[3][i] == '.' && lines[4][i] == '#') number += "3";
		else if (lines[0][i] == '#' && lines[1][i] == '#' && lines[2][i] == '#' && lines[3][i] == '.' && lines[4][i] == '.') number += "4";
		else if (lines[0][i] == '#' && lines[1][i] == '.' && lines[2][i] == '.' && lines[3][i] == '.' && lines[4][i] == '.') number += "7";
		else if (lines[0][i] == '.' && lines[1][i] == '.' && lines[2][i] == '.' && lines[3][i] == '.' && lines[4][i] == '.') continue;
		i += 3; //숫자 건너뛰기
	}
	return number;
}

int main() {
	cin >> n >> s;
	n = n / 5;

	int start = 0;
	for (int l = 0; l < 5; l++) {
		string line = s.substr(start, n);
		start += n;
		lines.push_back(line);
	}
	cout << solution();

	return 0;
}
