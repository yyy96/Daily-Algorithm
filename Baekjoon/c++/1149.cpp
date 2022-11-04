#include <iostream>
#include <algorithm>
using namespace std;

int n;
int house[1001][3] = { 0, };

int main() {
	int cost[3];
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[0] >> cost[1] >> cost[2];
		house[i][0] = min(house[i - 1][1], house[i - 1][2]) + cost[0]; //»¡°­ÀÌ·Á¸é, ÀÌÀü ÁýÀÌ ÃÊ·ÏorÆÄ¶û
		house[i][1] = min(house[i - 1][0], house[i - 1][2]) + cost[1]; //ÃÊ·ÏÀÌ·Á¸é, ÀÌÀü ÁýÀÌ »¡°­orÆÄ¶û
		house[i][2] = min(house[i - 1][1], house[i - 1][0]) + cost[2]; //ÆÄ¶ûÀÌ·Á¸é, ÀÌÀü ÁýÀÌ »¡°­orÃÊ·Ï
	}
	cout << min(house[n][2], min(house[n][0], house[n][1]));
}