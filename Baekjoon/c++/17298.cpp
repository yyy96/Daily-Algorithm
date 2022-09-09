#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n;
vector<int> nums;

vector<int> solution() {
	vector<int> result(n, -1);
	stack<int> s;

	for (int i = 0; i < n; i++) {
		int now = nums[i];
		while (!s.empty()) {
			int idx = s.top();
			if (now > nums[idx]) {
				result[idx] = now;
				s.pop();
			}
			else break;
		}
		//stack 에 나보다 작은 수가 없으므로(다 나보다 크므로) 나는 오큰수가 될 수 없음.
		//나보다 큰 수를 찾기 위한 대기 공간
		s.push(i);
	}

	return result;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}
	vector<int> result = solution();

	for (int i = 0; i < n; i++)
		cout << result[i] << " ";
	return 0;
}