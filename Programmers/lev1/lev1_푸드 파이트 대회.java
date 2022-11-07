public class Solution {
    public String solution(int[] food) {
        String answer = "";

        for(int i= food.length-1; i>0; i--){
            for(int j=0; j<food[i]/2; j++){
                answer = i + answer + i;
            }
        }
        return answer;
    }
}
