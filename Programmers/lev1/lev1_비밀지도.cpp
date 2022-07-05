#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<int>> getArr(int n, vector<int> arr) {
	vector<vector<int>> result;

	for (int k = 0; k < n; k++) {
		vector<int> line;
		int num = arr[k];
		for (int i = n - 1; i >= 0; i--) {
			int p = pow(2, i); // * pow = 2ÀÇ iÁ¦°ö / ex)2ÀÇ 3Á¦°ö=8
			if (num/p != 0) {
				line.push_back(1);
				num %= p;
			}
			else
				line.push_back(0);
		}
		result.push_back(line);
	}

	return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	vector<vector<int>> resultArr1 = getArr(n, arr1);
	vector<vector<int>> resultArr2 = getArr(n, arr2);

	for (int i = 0; i < n; i++) {
		string line = "";
		for (int j = 0; j < n; j++) {
			if (resultArr1[i][j] == 1 || resultArr2[i][j] == 1)
				line += "#";
			else
				line += " ";
		}
		answer.push_back(line);
	}

	return answer;
}

int main() {
	int n = 5;
	vector<int> arr1 = { 9, 20, 28, 18, 11 };
	vector<int> arr2 = { 30, 1, 21, 17, 28 };
	vector<string> answer = solution(n, arr1, arr2);

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
	return 0;
}