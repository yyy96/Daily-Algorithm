#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string result = "";

bool check(string num) {
	int len = num.size();
	int start = len - 1;

	//'인접'하기 위한 부분 수열은 최대 len/2 글자
	for (int i = 1; i <= len / 2; i++) {
		string sub = num.substr(start, i);
		string nextsub = num.substr(start - i, i);
		if (sub == nextsub) return false;
		start--;
	}
	return true;
}

void dfs(int lev, string num) {
	if (result != "") return;
	if (!check(num)) return;
	if (lev == n) {
		result = num;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		char c = i + '0';
		dfs(lev + 1, num + c);
	}
}

int main()
{
	cin >> n;
	dfs(0, "");
	cout << result;
	return 0;
}
