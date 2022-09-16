#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<long long> num;
int result = 0;

void solution() {
	if (n <= 2) return;

	for (int i = 0; i < n; i++) {
		//���� '����'�� �ΰ�?
		int number = num[i];
		//�̺� Ž��
		int s = 0, e = n - 1;
		while (s < e) {
			if (s == i) s++;
			if (e == i) e--;
			if (s >= e) break;

			int sum = num[s] + num[e];
			if (number > sum) s++;
			if (number < sum) e--;
			if (number == sum) {
				result++;
				break;
			}
		}
	}
}

int main()
{
	cin >> n;
	long long a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		num.push_back(a);
	}
	sort(num.begin(), num.end());
	solution();
	cout << result;
	return 0;
}