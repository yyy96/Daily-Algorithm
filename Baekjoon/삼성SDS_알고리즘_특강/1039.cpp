#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

struct Node {
	string n;
	int time;
};
string n;
int maxInt = -1;
int k;
queue<Node> q;

void fun() {
	q.push({ n,0 });

	while (!q.empty()) {
		unordered_map<string, int> used;
		int thisTimeChange = q.size();
		for (int t = 0; t < thisTimeChange; t++) {
			string n = q.front().n;
			int time = q.front().time;
			q.pop();

			if (time == k) {
				if (maxInt < stoi(n)) maxInt = stoi(n);
			}
			if (time > k) return;

			for (int i = 0; i < n.length() - 1; i++) {
				for (int j = i + 1; j < n.length(); j++) {
					if (i == 0 && n[j] == '0') continue;
					string newStr = n;
					int temp = newStr[i];
					newStr[i] = newStr[j];
					newStr[j] = temp;
					if (used[newStr] == 1) continue;
					used[newStr] = 1;
					q.push({ newStr,time + 1 });
				}
			}
		}
	}
}

int main() {
	cin >> n >> k;
	if (n.length() == 1 && k >= 1) {
	}
	else
		fun();

	cout << maxInt;

	return 0;
}