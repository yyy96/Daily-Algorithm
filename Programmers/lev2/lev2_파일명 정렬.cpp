#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct File {
	string head;
	string num;
	string tail;
};

bool compare(File a, File b) {
	//대소문자 맞추기
	transform(a.head.begin(), a.head.end(), a.head.begin(), ::toupper);
	transform(b.head.begin(), b.head.end(), b.head.begin(), ::toupper);
	if (a.head > b.head) return false;

	int n1 = stoi(a.num);
	int n2 = stoi(b.num);
	return n1 < n2;
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<File> file;

	//File 정리
	for (int i = 0; i < files.size(); i++) {
		string head, num, tail;
		int h = 0;
		for (h = 0; h < files[i].length(); h++) {
			if ('0' > files[i][h] || files[i][h] > '9') continue;
			head = files[i].substr(0, h);
			break;
		}
		for (int n = h + 1; n < files[i].length(); n++) {
			if ('0' <= files[i][n] && files[i][n] <= '9') continue;
			num = files[i].substr(h, n - h);
			tail = files[i].substr(n);
			break;
		}
		file.push_back({ head, num, tail });
	}
	cout << endl;
	sort(file.begin(), file.end(), compare);

	//일치하는 것 나열
	for (int i = 0; i < file.size(); i++) {
		string strfile = file[i].head + file[i].num + file[i].tail;
		answer.push_back(strfile);
	}

	return answer;
}

int main() {
	vector<string> files = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
	vector<string> answer = solution(files);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";

	return 0;
}