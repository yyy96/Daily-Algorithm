#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n, m;
unordered_map<long long, int> DAT;
vector<int> result;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		DAT[num] += 1;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		long long num;
		cin >> num;
		result.push_back(DAT[num]);
	}

	for (int i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);
	}

	return 0;
}