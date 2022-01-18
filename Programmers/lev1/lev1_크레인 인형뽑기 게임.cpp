#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> bucket;

	for (int i = 0; i < moves.size(); i++) {
		int line = moves[i] - 1; // �̰� �����ָ� out of range ����. size()���� ������ ������ �ȵǴ°� �ƴ� ����
		int next = 0;

		for (int j = 0; j < board.size(); j++) {
			if (board[j][line] != 0) {
				next = board[j][line];
				board[j][line] = 0;
				break;
			}
		}
		if (next == 0) continue;

		if (bucket.size() != 0 && bucket.top() == next) {
			bucket.pop();
			answer += 2;
		}
		else {
			bucket.push(next);
		}
	}
	return answer;
}

int main() {
	vector<vector<int>> board = {
		{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}
	};
	vector<int> moves = { 1,5,3,5,1,2,1,4 };

	cout << solution(board, moves);

	return 0;
}