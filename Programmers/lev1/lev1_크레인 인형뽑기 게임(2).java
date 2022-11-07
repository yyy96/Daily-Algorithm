import java.util.Stack;

class Solution {
    Stack<Integer> stack = new Stack<>();

    public boolean check(int doll) {
        if (stack.empty()) return true;
        if (stack.peek() == doll) {
            stack.pop();
            return false;
        }
        return true;
    }

    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        int n = board.length;
        for (int i : moves) {
            for (int j = 0; j < n; j++) {
                int line = moves[i] - 1;
                int doll = board[j][line];
                if (doll == 0) continue;
                if (check(doll)) stack.push(doll);
                else answer += 2;
                board[j][line] = 0;
                break;
            }
        }
        return answer;
    }
}