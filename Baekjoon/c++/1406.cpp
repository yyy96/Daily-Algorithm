#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int m;
char c;
string str;
stack<char> L, R;

int main() {
	cin >> str;
	cin >> m;
	for (int i = 0; i < str.length(); i++)
		L.push(str[i]);

	for (int i = 0; i < m; i++) {
		cin >> c;
		if (c == 'L' && !L.empty()) {
			R.push(L.top());
			L.pop();
		}
		if (c == 'D' && !R.empty()) {
			L.push(R.top());
			R.pop();
		}
		if (c == 'B' && !L.empty()) {
			L.pop();
		}
		if (c == 'P') {
			char word;
			cin >> word;
			L.push(word);
		}
	}

	while (!L.empty()) {
		R.push(L.top());
		L.pop();
	}
	while (!R.empty()) {
		cout << R.top();
		R.pop();
	}
	return 0;
}