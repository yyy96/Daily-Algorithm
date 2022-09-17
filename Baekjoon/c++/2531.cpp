#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n, d, k, c;
vector<int> dish;
unordered_map<int, int> used;
int result = 0;


void solution() {
	int e = 0;
	for (int i = 0; i < dish.size(); i++) {
		used[dish[i]]++;
		if (i < k - 1) continue;

		//���� ���
		used[c]++;

		//�ʹ� ���� ���� Ȯ��
		int cnt = used.size();
		result = max(result, cnt);

		//������ ����,���� ����
		used[dish[e]]--;
		if (used[dish[e]] == 0) used.erase(dish[e]);
		used[c]--;
		if (used[c] == 0) used.erase(c);
		e++;
	}
}


int main()
{
	cin >> n >> d >> k >> c;
	int f;
	for (int i = 0; i < n; i++) {
		cin >> f;
		dish.push_back(f);
	}
	for (int i = 0; i < k; i++) {
		dish.push_back(dish[i]);
	}
	solution();
	cout << result;
	return 0;
}