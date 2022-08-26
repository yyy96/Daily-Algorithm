#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long n;
long a, b, c; //범위 주의
vector<long> room;
long total = 0;

void solution() {
	total += n;
	for (long i = 0; i < n; i++) {
		long student = room[i];
		if (student <= b) continue;
		student -= b;

		long sub = student / c;
		if (student%c != 0) sub++;
		total += sub;
	}
}

int main() {
	cin >> n;
	for (long i = 0; i < n; i++) {
		cin >> a;
		room.push_back(a);
	}
	cin >> b >> c;
	solution();
	cout << total;
	return 0;
}