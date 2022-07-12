#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//�ùٸ� ���ڿ�
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

//�������� ���ڿ�
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
	//1.�� ���ڿ��� ��� ��ȯ
	if (v == "") {
		return v;
	}

	//2.�ΰ��� ���ڿ��� �и�. (u=���� ���ڿ�, v=������)
	string su = v.substr(0, balance(v) + 1);
	string sv = v.substr(balance(v) + 1);

	//3. u�� "�ùٸ� ���ڿ�" �̶�� ���ڿ� v�� ���� 2�ܰ���� �ٽ� ����
	if (validate(su)) {
		sv = dfs(sv);
		//3-1. ������ ��� ���ڿ��� u�� �̾� ���� �� ��ȯ
		return su + sv;
	}

	//4. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�"�� �ƴ϶��,
	//���ڿ� v�� ���� 2�ܰ���� ��������� ������ ��� ���ڿ��� �̾� ����
	string s = "(";
	s += dfs(sv);
	s += ")";
	su.erase(0, 1);
	su.erase(su.length() - 1, 1);
	//������ ���ڿ� ��ȣ ����� �ڿ� ����
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