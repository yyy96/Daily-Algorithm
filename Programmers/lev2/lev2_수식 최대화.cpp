#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<char> priority;
int used[3];
char path[3];
long long maxResult = 0;


void cal(vector<long long> number, vector<char> operation) {

	for (int t = 0; t < priority.size(); t++) { //������ ����
		for (int i = 0; i < operation.size(); i++) {
			if (operation[i] != path[t]) continue; //�켱����

			if (operation[i] == '+')
				number[i + 1] = number[i] + number[i + 1];
			else if (operation[i] == '-')
				number[i + 1] = number[i] - number[i + 1];
			else if (operation[i] == '*')
				number[i + 1] = number[i] * number[i + 1];

			number.erase(number.begin() + i);
			operation.erase(operation.begin() + i); //������ �����ڴ� ������� ���ڿ� index ��ġ�� �´´�
			i--;
		}
	}

	long long result = abs(number[0]);
	if (result > maxResult) maxResult = result;
}

void dfs(int lev, vector<long long> number, vector<char> operation) {
	if (lev == priority.size()) {
		cal(number, operation);
		return;
	}

	for (int i = 0; i < priority.size(); i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path[lev] = priority[i];
		dfs(lev + 1, number, operation);
		path[lev] = '\0';
		used[i] = 0;
	}
}

long long solution(string expression) {
	long long answer = 0;
	vector<long long> number;
	vector<char> operation;

	expression += ".";
	int plus_flag = 0;
	int minus_flag = 0;
	int mul_flag = 0;

	//���ڿ� �����ڸ� ����ش�
	int num_start = 0;
	for (int i = 0; i < expression.length(); i++) {
		if ('0' <= expression[i] && expression[i] <= '9') continue;
		string num = expression.substr(num_start, i - num_start + 1);
		number.push_back(stoi(num));
		num_start = i + 1;
		if (expression[i] != '.')
			operation.push_back(expression[i]);
		if (plus_flag == 0 && expression[i] == '+') {
			priority.push_back('+'); plus_flag = 1;
		}
		else if (minus_flag == 0 && expression[i] == '-') {
			priority.push_back('-'); minus_flag = 1;
		}
		else if (mul_flag == 0 && expression[i] == '*') {
			priority.push_back('*'); mul_flag = 1;
		}
	}

	//�������� �켱���� ����
	dfs(0, number, operation);

	answer = maxResult;
	return answer;
}

int main() {
	string expression = "100-200*300-500+20";
	cout << solution(expression);
	return 0;
}