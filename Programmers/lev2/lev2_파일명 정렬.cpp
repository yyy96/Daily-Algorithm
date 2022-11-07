#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct Files {
	int idx;
	string head;
	int num;
};

bool compare(Files a, Files b) {
	if (a.head < b.head) return true;
	else if (a.head > b.head) return false;

	if (a.num < b.num) return true;
	else if (a.num > b.num) return false;

	return a.idx < b.idx;
}

vector<Files> splitInfo(vector<string> files) {
	vector<Files> fileInfo;

	for (int f = 0; f < files.size(); f++) {
		string head = "", num = "", tail = ""; //tail은 정렬에서 활용되지 않음
		int headLast = 0, numLast = 0;
		//HEAD
		for (int i = 0; i < files[f].length(); i++) {
			if (files[f][i] >= '0' && files[f][i] <= '9') {
				headLast = i - 1;
				break;
			}
			head += files[f][i];
		}
		transform(head.begin(), head.end(), head.begin(), ::tolower);
		//NUMBER
		for (int i = headLast + 1; i <= files[f].length(); i++) {
			if (i == files[f].length()) numLast = i - 1;
			if (files[f][i] < '0' || files[f][i] > '9') {
				numLast = i - 1;
				break;
			}
			num += files[f][i];
		}
		fileInfo.push_back({ f, head, stoi(num) });
	}
	return fileInfo;
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<Files> fileInfo = splitInfo(files);

	sort(fileInfo.begin(), fileInfo.end(), compare);
	for (int i = 0; i < fileInfo.size(); i++)
		answer.push_back(files[fileInfo[i].idx]);
	return answer;
}

int main() {
	vector<string> files = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
	solution(files);
	return 0;
}