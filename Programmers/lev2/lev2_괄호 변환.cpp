#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//올바른 문자열
bool validate(string u) {
	stack<char> result;
	for (int i = 0; i < u.length(); i++) {
		if (u[i] == '(')
			result.push(u[i]);
		else {
			if (result.size() == 0) return false;
			result.pop();
		}
	}

	if (result.size() > 0)
		return false;
	return true;
}

//균형잡힌 문자열
int balance(string u) {
	int opencnt = 0;
	int closecnt = 0;

	if (u == "") return 0;
	for (int i = 0; i < u.length(); i++) {
		if (u[i] == '(') opencnt++;
		else closecnt++;

		if (opencnt == closecnt)
			return i;
	}
	return 0;
}

string flip(string u) {
	string s = "";
	for (int i = 0; i < u.length(); i++) {
		if (u[i] == '(') s += ")";
		else s += "(";
	}
	return s;
}

string dfs(string v) {
	//1.빈 문자열일 경우 반환
	if (v == "") {
		return v;
	}

	//2.두개의 문자열로 분리. (u=균형 문자열, v=나머지)
	string su = v.substr(0, balance(v) + 1);
	string sv = v.substr(balance(v) + 1);

	//3. u가 "올바른 문자열" 이라면 문자열 v에 대해 2단계부터 다시 수행
	if (validate(su)) {
		sv = dfs(sv);
		//3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환
		return su + sv;
	}

	//4. 문자열 u가 "올바른 괄호 문자열"이 아니라면,
	//문자열 v에 대해 2단계부터 재귀적으로 수행한 결과 문자열을 이어 붙임
	string s = "(";
	s += dfs(sv);
	s += ")";
	su.erase(0, 1);
	su.erase(su.length() - 1, 1);
	//나머지 문자열 괄호 뒤집어서 뒤에 붙임
	s += flip(su);
	return s;
}

string solution(string p) {
	string answer = dfs(p);
	return answer;
}

int main() {
	string p = "()))((()";
	cout << solution(p);
	return 0;
}