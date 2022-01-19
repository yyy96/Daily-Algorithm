#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

struct Hand {
	int x, y;
};
int keypad[4][3] = {
	{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}
};
int direct[4][2] = {
	{-1,0},{1,0},{0,1},{0,-1}
};

void findKey(int number, int &x, int &y) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (keypad[i][j] == number) {
				x = i;
				y = j;
				return;
			}
		}
	}
}

string solution(vector<int> numbers, string hand) {
	string answer = "";
	Hand R = { 3,0 };
	Hand L = { 3,2 };

	for (int i = 0; i < numbers.size(); i++) {
		int x, y;
		findKey(numbers[i], x, y);

		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
			L.x = x; L.y = y;
			answer += "L";
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			R.x = x; R.y = y;
			answer += "R";
		}
		else {
			if ((abs(R.x - x) + abs(R.y - y)) < (abs(L.x - x) + abs(L.y - y))) { //오른손이 더 가깝다면
				R.x = x; R.y = y;
				answer += "R";
			}
			else if ((abs(R.x - x) + abs(R.y - y)) > (abs(L.x - x) + abs(L.y - y))) {
				L.x = x; L.y = y;
				answer += "L";
			}
			else {
				if (hand == "right") {
					R.x = x; R.y = y;
					answer += "R";
				}
				else {
					L.x = x; L.y = y;
					answer += "L";
				}
			}
		}
	}
	return answer;
}

int main() {
	vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
	string hand = "right";

	cout << solution(numbers, hand);

	return 0;
}