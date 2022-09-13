#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n, k;
vector<int> words;
int result = 0;

void check(int keys) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (words[i] == (keys & words[i])) cnt++;
	}
	result = max(result, cnt);
}

void dfs(int lev, char start, int keys) {
	if (lev == k - 5) {
		check(keys);
		return;
	}

	for (char i = start; i <= 'z'; i++) {
		int c = 1 << (i - 'a');
		if (keys == (keys | c)) continue;
		dfs(lev + 1, i + 1, keys | c); //이렇게 해줘서 used 필요x
		//주의) keys|=c 하면 안된다. 그럼 해당 lev의 keys 가 바뀜
	}
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;

		//알파벳 26개이면 2^26 밖에 안되서 int 비트마스킹 가능!
		int key = 0;
		for (int j = 0; j < word.length(); j++) {
			int c = 1 << (word[j] - 'a');
			key |= c;
		}
		words.push_back(key);
	}

	//기본 a,n,t,i,c 설정
	int keys = 0;
	keys |= (1 << ('a' - 'a'));
	keys |= (1 << ('n' - 'a'));
	keys |= (1 << ('t' - 'a'));
	keys |= (1 << ('i' - 'a'));
	keys |= (1 << ('c' - 'a'));

	if (k >= 5 && k < 26) dfs(0, 'a', keys);
	if (k >= 26) result = n;
	cout << result;
	return 0;
}