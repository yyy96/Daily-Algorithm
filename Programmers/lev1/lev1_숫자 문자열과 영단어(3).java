import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        String[] alpha = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        for (int i = 0; i < 10; i++) {
            s = s.replaceAll(alpha[i], Integer.toString(i));
        }
        answer = Integer.parseInt(s);
        return answer;
    }
}