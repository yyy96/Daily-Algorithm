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

		//uno에서는 순서가 달라도 상관없음. == 연산가능
		if (usedS == usedT) cnt++;

		//슬라이딩 윈도우이므로 마지막 글자를 지워줌
		int last = i - (T.length() - 1);
		usedS[S[last]]--;

		//만약 지우고나서 이제 0이라면 공간 자체를 지워줘야 차이가 안남
		//만약 마지막을 지웠는데 같은 글자가 여러 개였으면 아직 글자가 남아있음
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