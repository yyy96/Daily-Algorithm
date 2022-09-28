#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; //키워드, 글
	unordered_set<string> keywords; //메모장 키워드 (사용후 삭제)

	cin >> n >> m;

	string k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		keywords.insert(k);
	}

	string str;
	for (int i = 0; i < m; i++) {
		cin >> str;
		str += ",";

		string word;
		int s = 0, e = 0;
		while (s < str.length() - 1) {
			e = str.find(',', s);
			word = str.substr(s, e - s);

			if (keywords.find(word) != keywords.end())
				keywords.erase(word);

			s = e + 1;
		}
		cout << keywords.size() << "\n";
	}
	return 0;
}