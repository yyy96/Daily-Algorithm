#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct Line {
	int s, e;
	int cnt;
};
string str;
vector<Line> stick;
vector<Line> cutt;

int solution() {
	int result = 0;
	stack<int> s;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') s.push(i);
		else {
			int open = s.top();
			if (i - open == 1) cutt.push_back({ open, i });
			else stick.push_back({ open, i, 1 });
			s.pop();
		}
	}

	for (int i = 0; i < cutt.size(); i++) {
		for (int j = 0; j < stick.size(); j++) {
			if (stick[j].s < cutt[i].s && cutt[i].e < stick[j].e)
				stick[j].cnt++;
		}
	}

	for (int i = 0; i < stick.size(); i++)
		result += stick[i].cnt;
	return result;
}

int main() {
	cin >> str;
	cout << solution();
	return 0;
}