#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int n;
string str;
int result =0;

int cal(int a, int b, char c) {
	if (c == '+') return a + b;
	if (c == '-') return a - b;
	if (c == '*') return a * b;
}

void dfs(int lev, int sum) {
	if (lev >= n) {
		result = max(result, sum);
		return;
	}

	char c = lev == 0 ? '+' : str[lev - 1];

	//��ȣo = ����+ ��ȣ ���
	if (lev + 2 < n) {
		int bracket = cal(str[lev] - '0', str[lev + 2] - '0', str[lev + 1]);
		int num = cal(sum, bracket, c); //����) sum = cal(sum, bracket, c) �ϸ� �ȵ�. �׷��� ���� �� lev�� sum ���� return �Ŀ��� ����Ǿ�����
		dfs(lev + 4, num);
	}

	//��ȣx = ���� + ���� ���
	int num = cal(sum, str[lev] - '0', c);
	dfs(lev + 2, num);
}

int main() {
	cin >> n >> str;
	dfs(0, 0);
	cout << result;
	return 0;
}