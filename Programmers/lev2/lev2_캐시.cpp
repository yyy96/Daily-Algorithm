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
				cache[j].time = i + 1; //i번째 검색 = 최근 사용 기록
				break;
			}
		}

		//존재x 새로운 도시를 넣고, 가장 used 가 적은걸 제외
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