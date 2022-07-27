#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Cache {
	string str;
	int time;
};

bool compare(Cache a, Cache b) {
	return a.time < b.time;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	int totalTime = 0;
	vector<Cache> cache(cacheSize);

	if (cacheSize == 0) return cities.size() * 5;

	for (int i = 0; i < cities.size(); i++) {
		bool exist = false;
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);

		for (int j = 0; j < cacheSize; j++) {
			if (cache[j].str == cities[i]) {
				exist = true;
				totalTime += 1;
				cache[j].time = i + 1; //i��° �˻� = �ֱ� ��� ���
				break;
			}
		}

		//����x ���ο� ���ø� �ְ�, ���� used �� ������ ����
		if (exist) continue;
		sort(cache.begin(), cache.end(), compare);
		cache.erase(cache.begin());
		cache.push_back({ cities[i],i + 1 });
		totalTime += 5;
	}
	return totalTime;
}

int main() {
	int cacheSize = 0;
	vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
	cout << solution(cacheSize, cities);
	return 0;
}