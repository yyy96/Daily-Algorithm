#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<long long> result;

//������ ������ �ִ� ���� 9876543210 �� �ִ� 10�ڸ� lev=10
void dfs(int lev, long long num) {
	if (lev >= 10) return;

	result.push_back(num);
	for (int i = 0; i <= 9; i++) {
		if (num % 10 <= i) continue; //������ ���� �� �ڸ� ������ �۾ƾ���
		dfs(lev + 1, num * 10 + i);  //ex. 32 -> 321
	}
}

int main()
{
	cin >> n;

	//������ �ڸ��� ������ �����̾��°�. (�װ� ���߿��� ���� ���ڸ��� ��)
	for (int i = 0; i < 10; i++)
		dfs(0, i);

	sort(result.begin(), result.end());

	if (result.size() <= n) cout << "-1";
	else cout << result[n];
	return 0;
}