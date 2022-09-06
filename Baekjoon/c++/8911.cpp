#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

enum Direct {
	UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3
};
struct Node {
	int x, y;
	int dir;
};
Node n;

void moving(int move) {
	if (n.dir == UP) n.x += move;
	if (n.dir == DOWN) n.x -= move;
	if (n.dir == RIGHT) n.y += move;
	if (n.dir == LEFT) n.y -= move;
}
void turn(int dir) {
	n.dir += dir;
	if (n.dir > 3) n.dir -= 4;
	if (n.dir < 0) n.dir += 4;
}

int solution(string move) {
	int side[4] = { 0, }; //상,하,좌,우

	for (int i = 0; i < move.length(); i++) {
		if (move[i] == 'F') moving(1);
		if (move[i] == 'B') moving(-1);
		if (move[i] == 'R') turn(1);
		if (move[i] == 'L') turn(-1);

		//가장 side 인지 체크
		if (n.x > side[0]) side[0] = n.x; //상
		if (n.x < side[1]) side[1] = n.x; //하
		if (n.y < side[2]) side[2] = n.y; //좌
		if (n.y > side[3]) side[3] = n.y; //우
	}

	//사각형 계산
	int x = abs(side[3] - side[2]);
	int y = abs(side[0] - side[1]);
	return x * y;
}

int main() {
	int T;
	string str;

	cin >> T;
	while (T--) {
		n = { 0,0,UP };
		cin >> str;
		cout << solution(str) << endl;
	}
	return 0;
}