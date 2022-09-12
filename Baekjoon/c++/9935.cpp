#include <iostream>
#include <string>
#include <deque>

using namespace std;

string str, word;
deque<char> d;

bool check() {
	for (int i = 0; i < word.size(); i++) {
		if (d[d.size() - i - 1] != word[word.size() - i - 1]) return false;
	}
	return true;
}

void solution() {
	for (int i = 0; i < str.length(); i++) {
		d.push_back(str[i]);

		// ������ ���ڰ� ���� �� üũ(����ġ��)
		if (d.size() < word.size() || str[i] != d.back()) continue;

		// ���� ���ڿ��� �´ٸ� ����(��)���� ����
		if (check())
			for (size_t i = 0; i < word.size(); i++) d.pop_back();
	}

	if (d.empty()) {
		cout << "FRULA";
		return;
	}
	for (size_t i = 0; i < d.size(); i++)
		cout << d[i];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str >> word;
	solution();
	return 0;
}