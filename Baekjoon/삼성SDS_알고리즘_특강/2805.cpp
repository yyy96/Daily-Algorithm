#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> tree;

bool fun(int mid) {
	long long totalCut = 0;
	int i = 0;
	while (i < N) {
		if (tree[i] < mid) break;
		int cut = tree[i] - mid;
		totalCut += cut;
		i++;
		if (totalCut >= M) return true;
	}
	return false;
}

int main() {
	cin >> N >> M;
	int  mid = 0;
	int Start = 0;
	int End = 0;

	for (int i = 0; i < N; i++) {
		int H;
		cin >> H;
		tree.push_back(H);
		if (End < H) End = H;
	}
	sort(tree.rbegin(), tree.rend());

	int result = 0;
	while (Start <= End) {
		mid = (Start + End) / 2;
		if (fun(mid)) {
			result = mid;
			Start = mid + 1;
		}
		else {
			End = mid - 1;
		}
	}
	cout << result;

	return 0;
}