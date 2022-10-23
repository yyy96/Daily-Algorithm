#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<string> str(5);
int maxLen = 0;
string result = "";

int main()
{
	for (int i = 0; i < 5; i++) {
		cin >> str[i];
		if (str[i].length() > maxLen) maxLen = str[i].length();
	}

	for (int i = 0; i < maxLen; i++) {
		for (int j = 0; j < 5; j++) {
			if (str[j].length() <= i) continue;
			result += str[j][i];
		}
	}
	cout << result;
	return 0;
}