import java.util.*;

class Solution {
    public String[] solution(String[] files) {
        String[] answer = new String[files.length];
        ArrayList<Files> fileInfo = new ArrayList<>();

        //파일 정보 정리
        int idx = 0;
        for (String file : files) {
            fileInfo.add(splitInfo(idx, file));
            idx++;
        }

        //파일 정렬
        Collections.sort(fileInfo, Collections.reverseOrder());
        int i = 0;
        for (Files file : fileInfo) {
            answer[i] = file.toString();
            i++;
        }
        return answer;
    }

    public Files splitInfo(int idx, String file) {
        String head = "", number = "", tail = "";
        int headLastIdx = 0, numLastId = 0;
        for (int i = 0; i < file.length(); i++) {
            char c = file.charAt(i);
            if ('0' <= c && c <= '9') {
                headLastIdx = i - 1;
                break;
            }
            head += c;
        }
        for (int i = headLastIdx + 1; i <= file.length(); i++) {
            if (i == file.length())
                return new Files(idx, head, number, tail);
            char c = file.charAt(i);
            if ('0' > c || c > '9') {
                numLastId = i - 1;
                break;
            }
            number += c;
        }
        tail = file.substring(numLastId + 1);
        return new Files(idx, head, number, tail);
    }
}

class Files implements Comparable<Files> {
    int idx;
    String head;
    String number;
    String tail;

    public Files(int idx, String head, String number, String tail) {
        this.idx = idx;
        this.head = head;
        this.number = number;
        this.tail = tail;
    }

    @Override
    public String toString() {
        if (tail == null) return head + number;
        return head + number + tail;
    }

    @Override
    public int compareTo(Files o) {
        if (this.head.compareToIgnoreCase(o.head) < 0) return 1;
        if (this.head.compareToIgnoreCase(o.head) > 0) return -1;
        if (Integer.parseInt(this.number) < Integer.parseInt(o.number)) return 1;
        if (Integer.parseInt(this.number) > Integer.parseInt(o.number)) return -1;
        if (this.idx > o.idx) return -1;
        return 1;
    }
}