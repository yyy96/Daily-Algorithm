#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

string str;
unordered_map<char, int> cnt;
unordered_map<char, bool> used;
string result = "";

//dfs = 95ms VS hash = 2ms (효율적 풀이)
void solution() {
	for (char c : str) {
		cnt[c]--;
		if (used[c] == 1) continue;

		while (result.size() != 0) {
			char last = result.back();
			if (last <= c || cnt[last] <= 0) break;

			used[last] = 0;
			result.pop_back();
		}
		result += c;
		used[c] = 1;
	}
}

int main() {
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if ('a' <= str[i] && str[i] <= 'z') str[i] -= 32;
		char c = str[i];
		cnt[c]++;
	}
	solution();
	cout << result;
	return 0;
}