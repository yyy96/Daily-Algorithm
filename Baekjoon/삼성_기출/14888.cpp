#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

enum Math
{
	add, sub, mul, divide
};

int n;
int number[12];
int symbol[4] = { add, sub, mul, divide };
int math[4];
int path[12];
int maxResult = -21e8;
int minResult = 21e8;

void cal() {
	int sum = number[0];

	for (int i = 0; i < n - 1; i++) {
		if (path[i] == add) {
			sum += number[i + 1];
		}
		else if (path[i] == sub) {
			sum -= number[i + 1];
		}
		else if (path[i] == mul) {
			sum *= number[i + 1];
		}
		else if (path[i] == divide) {
			sum /= number[i + 1];
		}
	}

	if (sum > maxResult) maxResult = sum;
	if (sum < minResult) minResult = sum;
}

void fun(int lev) {
	if (lev == n-1) {
		cal();
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (math[i] == 0) continue;
		math[i]--;
		path[lev] = symbol[i];
		fun(lev + 1);
		path[lev] = 0;
		math[i]++;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> number[i];

	for (int i = 0; i < 4; i++)
		cin >> math[i];

	fun(0);

	cout << maxResult << "\n" << minResult;

	return 0;
}