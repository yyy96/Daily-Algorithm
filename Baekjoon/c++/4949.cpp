#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string solution(string str) {
	stack<int> small;
	stack<int> big;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') small.push(i);
		if (str[i] == '[') big.push(i);
		if (str[i] == ')') {
			if (small.empty()) return "no";
			if (!big.empty() && small.top() < big.top()) return "no";
			small.pop();
		}
		if (str[i] == ']') {
			if (big.empty()) return "no";
			if (!small.empty() && small.top() > big.top()) return "no";
			big.pop();
		}
	}

	if (small.empty() && big.empty()) return "yes";
	return "no";
}

int main()
{
	while (1) {
		string str;
		getline(cin, str);
		if (str == ".") break;
		cout << solution(str) << endl;
	}
	return 0;
}
