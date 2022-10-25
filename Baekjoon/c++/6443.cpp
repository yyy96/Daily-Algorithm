#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	//순열
	while (n--) {
		string str;
		cin >> str;

		sort(str.begin(), str.end());

		do cout << str << '\n';
		while (next_permutation(str.begin(), str.end()));
	}
}