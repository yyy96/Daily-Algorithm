#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#define ENDTIME 1439 //23(*60)+59
using namespace std;

int getTime(string time) {
	string h = time.substr(0, 2);
	string m = time.substr(3, 2);
	return stoi(h) * 60 + stoi(m);
}

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	vector<int> cars[10000]; //차는 최대 4자리

	//차 시간 정리
	for (int i = 0; i < records.size(); i++) {
		string time, num, inout;
		stringstream ss(records[i]);
		ss >> time >> num >> inout;
		cars[stoi(num)].push_back(getTime(time));
	}

	//어차피 차 번호 작은 순서대로 접근
	for (int i = 0; i < 10000; i++) if (!cars[i].empty()) {
		if (cars[i].size() == 1) cars[i].push_back(ENDTIME);

		int times = 0;
		for (int j = 1; j < cars[i].size(); j += 2)
			times += cars[i][j] - cars[i][j - 1];

		int fee = fees[1];
		if (times > fees[0])
			fee += (times - fees[0] + fees[2] - 1) / fees[2] * fees[3];
		answer.push_back(fee);
	}
	return answer;
}

int main() {
	vector<int> fees = { 180, 5000, 10, 600 };
	vector<string> records = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };
	vector<int> answer = solution(fees, records);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
}