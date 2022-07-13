#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, int> s1; //다중집합 DAT
unordered_map<string, int> s2; //다중집합 DAT
unordered_map<string, int> s3; //합집합

vector<string> sg1; //다중 집합
vector<string> sg2; //다중 집합


void multigroup(string str1, string str2) {
	//1. 대소문자 일치시키기.
	for (int i = 0; i < str1.length(); i++) {
		if ('a' <= str1[i] && str1[i] <= 'z')
			str1[i] -= 32;
	}
	for (int i = 0; i < str2.length(); i++) {
		if ('a' <= str2[i] && str2[i] <= 'z')
			str2[i] -= 32;
	}

	//2. 다중 집합 만들기(문자열 버리기)
	for (int i = 0; i < str1.length() - 1; i++) {
		if ('A' > str1[i] || str1[i] > 'Z' || 'A' > str1[i + 1] || str1[i + 1] > 'Z') continue;
		string str;
		str += str1[i];
		str += str1[i + 1];
		sg1.push_back(str);
	}
	for (int i = 0; i < str2.length() - 1; i++) {
		if ('A' > str2[i] || str2[i] > 'Z' || 'A' > str2[i + 1] || str2[i + 1] > 'Z') continue;
		string str;
		str += str2[i];
		str += str2[i + 1];
		sg2.push_back(str);
	}
}

int findinter() {
	int intercnt = 0;
	for (auto i = s1.begin(); i != s1.end(); ++i) {
		for (auto j = s2.begin(); j != s2.end(); ++j) {
			if (i->first != j->first) continue;
			intercnt += min(i->second, j->second);
		}
	}
	return intercnt;
}

int findunion() {
	int unioncnt = 0;
	for (auto i = s1.begin(); i != s1.end(); ++i) {
		s3[i->first] = i->second;
	}
	for (auto i = s2.begin(); i != s2.end(); ++i) {
		/// map 조건 유의
		if (s3.count(i->first) == 0 || s3[i->first] < i->second) {
			s3[i->first] = i->second;
		}
	}
	for (auto i = s3.begin(); i != s3.end(); ++i) {
		unioncnt += i->second;
	}
	return unioncnt;
}

int solution(string str1, string str2) {
	int answer = 1;
	int intercnt = 0;
	int unioncnt = 0;

	//init
	multigroup(str1, str2);
	for (int i = 0; i < sg1.size(); i++) {
		s1[sg1[i]]++;
	}
	for (int i = 0; i < sg2.size(); i++) {
		s2[sg2[i]]++;
	}

	if (s1.size() != 0 || s2.size() != 0) {
		intercnt = findinter();
		unioncnt = findunion();
		double percent = (double)intercnt / (double)unioncnt;
		return (int)(percent * 65536);
	}
	return answer * 65536;
}

int main() {
	string str1 = "BAAAA";
	string str2 = "AAA";
	cout << solution(str1, str2);
	return 0;
}