#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;

int n, k, x;
deque <bool> robot;
deque <int> belt;
int zero = 0;
int time = 0;

void solution() {
	while (zero < k) {
		// 1. 벨트 회전
		belt.push_front(belt.back());
		belt.pop_back();

		// 1. 로봇 회전
		robot.push_front(robot.back());
		robot.pop_back();
		if (robot[n - 1] == true) robot[n - 1] = false;


		// 2. 로봇 이동
		for (int i = n - 2; i >= 0; i--) {
			if (robot[i] == true && robot[i + 1] == false && belt[i + 1] >= 1) {
				robot[i] = false;
				belt[i + 1]--;
				if (belt[i + 1] == 0) zero++;
				if (i == n - 2) continue; // i+1 == n-1, 로봇이 즉시 땅에 내려감
				robot[i + 1] = true;
			}
		}

		// 3. 로봇 올리기
		if (belt[0] >= 1 && robot[0] == false) {
			robot[0] = true;
			belt[0]--;
			if (belt[0] == 0) zero++;
		}
		time++;
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < 2 * n; i++) {
		cin >> x;
		belt.push_back(x);
		robot.push_back(false);
	}
	solution();
	cout << time;
}