#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

string str1;
string str2;
int LCS[4002][4002] = { 0, };
int maxLen = 0;

int main() {
	cin >> str1 >> str2;

	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < str2.length(); j++) {
			if (str1[i] != str2[j]) // �� ���ڰ� �ٸ��ٸ� 0
				LCS[i][j] = 0;
			else { // �� ���ڰ� ���ٸ� LCS[i-1][j-1]+1
				if (i == 0 || j == 0) //i==0, j==0 �̶�� LCS[-1][-1] �̹Ƿ� �׳� 0+1
					LCS[i][j] = 1;
				else
					LCS[i][j] = LCS[i - 1][j - 1] + 1;

				if (maxLen < LCS[i][j]) maxLen = LCS[i][j];
			}
		}
	}

	cout << maxLen;

	return 0;
}