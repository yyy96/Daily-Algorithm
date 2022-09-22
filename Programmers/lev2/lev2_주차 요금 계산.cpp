#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>
using namespace std;

struct Car {
	int num; int fee = 0;
};
struct Time {
	int in; int out = 1439; //23(*60)+59
};

int getTime(string time) {
	string h = time.substr(0, 2);
	string m = time.substr(3, 2);
	return stoi(h) * 60 + stoi(m);
}

int getFee(vector<int> fees, int times) {
	int fee = fees[1];
	if (times < fees[0]) return fee;

	times -= fees[0];
	if (times%fees[2] != 0) fee += (times / fees[2] + 1)*fees[3];
	else fee += (times / fees[2])*fees[3];
	return fee;
}

bool compare(Car a, Car b) {
	return a.num < b.num;
}

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	unordered_map<int, Time> cars;
	unordered_map<int, int> cr; //시간 누적
	vector<Car> result; //요금 계산

	//차 누적 시간 계산
	for (int i = 0; i < records.size(); i++) {
		string time, num, inout;
		stringstream ss(records[i]);
		ss >> time >> num >> inout;

		int car = stoi(num);
		if (inout == "IN") cars[car] = { getTime(time) };
		else {
			cars[car].out = getTime(time);
			cr[car] += cars[car].out - cars[car].in; //update
			cars.erase(car); //출차
		}
	}

	//출차가 안된 차들 누적 시간 update
	for (auto i = cars.begin(); i != cars.end(); ++i) {
		int car = i->first;
		cr[car] += cars[car].out - cars[car].in; //update
	}

	//요금 계산
	for (auto i = cr.begin(); i != cr.end(); ++i) {
		int car = i->first;
		int fee = getFee(fees, i->second);
		result.push_back({ car,fee });
	}

	//차 번호 정렬
	sort(result.begin(), result.end(), compare);
	for (int i = 0; i < result.size(); i++)
		answer.push_back(result[i].fee);
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