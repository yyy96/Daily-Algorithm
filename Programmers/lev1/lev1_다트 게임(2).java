import java.util.Vector;

class Solution {
    public int solution(String dartResult) {
        int answer = 0;
        int num = 0;
        Vector<Integer> nums = new Vector<>();

        for (int i = 0; i < dartResult.length(); i++) {
            char c = dartResult.charAt(i);
            if (c == 'S' || c == 'D' || c == 'T') {
                if (c == 'S') nums.add(num);
                if (c == 'D') nums.add(num * num);
                if (c == 'T') nums.add(num * num * num);
                continue;
            }
            if (c == '*') {
                int lastIdx = nums.size() - 1;
                if (lastIdx >= 1) nums.set(lastIdx - 1, nums.get(lastIdx - 1) * 2);
                nums.set(lastIdx, nums.get(lastIdx) * 2);
                continue;
            }
            if (c == '#') {
                int lastIdx = nums.size() - 1;
                nums.set(lastIdx, 0 - nums.get(lastIdx));
                continue;
            }
            if (num == 1 && c == '0') num = 10;
            else num = c - '0';
        }

        for (int n : nums)
            answer += n;
        return answer;
    }
}