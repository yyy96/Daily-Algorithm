import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        ArrayList<User> users = new ArrayList<>();
        HashMap<String, Integer> callingCnt = new HashMap<>(); //신고된 수
        HashMap<String, Integer> idIdx = new HashMap<>();
        int idx = 0;

        for (String name : id_list) {
            idIdx.put(name, idx++);
            users.add(new User(name));
        }

        for (String str : report) {
            String[] names = str.split(" ");
            users.get(idIdx.get(names[0])).report.add(names[1]);
            users.get(idIdx.get(names[1])).reported.add(names[0]);
        }

        for (User user : users) {
            callingCnt.put(user.name, user.reported.size());
        }

        int i = 0;
        for (User user : users) {
            for (String name : user.report) {
                if (callingCnt.get(name) >= k)
                    answer[i]++;
            }
            i++;
        }

        return answer;
    }
}

class User {
    String name;
    HashSet<String> report = new HashSet<>();
    HashSet<String> reported = new HashSet<>();

    public User(String name) {
        this.name = name;
    }
}