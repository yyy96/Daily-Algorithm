#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

string S, T;
unordered_map<char, int> usedS, usedT;

int solution() {
	int cnt = 0;
	for (auto i : T)
		usedT[i]++;

	for (int i = 0; i < S.length(); i++) {
		usedS[S[i]]++;
		if (i < T.length() - 1) continue;

		//uno������ ������ �޶� �������. == ���갡��
		if (usedS == usedT) cnt++;

		//�����̵� �������̹Ƿ� ������ ���ڸ� ������
		int last = i - (T.length() - 1);
		usedS[S[last]]--;

		//���� ������� ���� 0�̶�� ���� ��ü�� ������� ���̰� �ȳ�
		//���� �������� �����µ� ���� ���ڰ� ���� �������� ���� ���ڰ� ��������
		if (usedS[S[last]] == 0) usedS.erase(S[last]);
	}
	return cnt;
}

int main() {
	/*
	S = abbabbabba
	T = abb
	cnt = 8
	*/

	cin >> S >> T;
	cout << solution();
	return 0;
}