#include <iostream>
#include <string>
#include <algorithm>
#define MAX 10001
using namespace std;

int n, x;
vector<int> blog;
int maxN = 0;
int maxX = 0;

//sliding window
int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		blog.push_back(a);
	}

	int s = 0; int total = 0;
	for (int i = 0; i < n; i++) {
		total += blog[i];
		if (i < x - 1) continue;

		if (maxN < total) {
			maxN = total;
			maxX = 1;
		}
		else if (maxN == total) maxX++;
		if (s < n - x) total -= blog[s];
		s++;
	}

	if (maxN == 0) cout << "SAD";
	else cout << maxN << endl << maxX;
	return 0;
}
