#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n;

vector<int> solution(vector<int> tops) {
	stack<int> s;
	vector<int> result(n, 0);

	for (int i = n - 1; i >= 0; i--) {
		int now = tops[i];
		while (!s.empty()) {
			int idx = s.top();
			if (now > tops[idx]) {
				result[idx] = i + 1;
				s.pop();
			}
			else break;
		}
		s.push(i);
	}
	return result;
}

int main() {
	cin >> n;

	vector<int> tops(n);
	for (int i = 0; i < n; i++)
		cin >> tops[i];

	vector<int> result = solution(tops);
	for (int i = 0; i < n; i++)
		cout << result[i] << " ";
	return 0;
}