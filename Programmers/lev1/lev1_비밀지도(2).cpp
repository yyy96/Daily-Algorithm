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
			if (num % 2 == 1) line = "#" + line; //�պ��� ä������.
			else line = " " + line;
			num = num >> 1; //10�����̹Ƿ� for�� ��� ��Ʈ�� �Űܼ� ���� ����
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