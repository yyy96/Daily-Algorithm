#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	for (int i = 0; i < n; i++) {
		int num = arr1[i] | arr2[i];

		string line = "";
		for (int j = 0; j < n; j++) {
			if (num % 2 == 1) line = "#" + line; //앞부터 채워나감.
			else line = " " + line;
			num = num >> 1; //10진수이므로 for문 대신 비트를 옮겨서 다음 차례
		}
		answer.push_back(line);
	}
	return answer;
}

int main() {
	int n = 5;
	vector<int> arr1 = { 9,20,28,18,11 };
	vector<int> arr2 = { 30,1,21,17,28 };
	vector<string> answer = solution(n, arr1, arr2);
	for (int i = 0; i < n; i++)
		cout << answer[i] << endl;
	return 0;
}