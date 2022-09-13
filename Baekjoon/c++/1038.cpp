#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<long long> result;

//어차피 가능한 최대 수는 9876543210 로 최대 10자리 lev=10
void dfs(int lev, long long num) {
	if (lev >= 10) return;

	result.push_back(num);
	for (int i = 0; i <= 9; i++) {
		if (num % 10 <= i) continue; //마지막 수는 앞 자리 수보다 작아야함
		dfs(lev + 1, num * 10 + i);  //ex. 32 -> 321
	}
}

int main()
{
	cin >> n;

	//마지막 자리의 시작이 무엇이었는가. (그게 나중에는 가장 앞자리가 됨)
	for (int i = 0; i < 10; i++)
		dfs(0, i);

	sort(result.begin(), result.end());

	if (result.size() <= n) cout << "-1";
	else cout << result[n];
	return 0;
}