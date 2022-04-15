#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> path;
vector<string> result;
int used[10000];

void finalRoot() {
	for (int i = 0; i < path.size(); i++) {
		result.push_back(path[i]);
	}
}

void dfs(int lev, string start, vector<vector<string>> tickets) {
	if (!result.empty()) return; //정렬된 상태에서는 첫 결과가 최종결과이다. (가지치기-시간단축)
	if (lev == tickets.size()) {
		path.push_back(start);   //마지막 장소 넣어주기
		finalRoot();
		return;
	}

	for (int i = 0; i < tickets.size(); i++) {
		if (start != tickets[i][0]) continue; //현재 출발지인 티켓인가
		if (used[i] == 1) continue; //현재 이 티켓을 사용했는가
		path.push_back(start);
		used[i] = 1;
		dfs(lev + 1, tickets[i][1], tickets);
		used[i] = 0;        //한 붓 긋기가 안될 경우 다시 return
		path.pop_back();    //넣어주었던 경로도 다시 삭제
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	sort(tickets.begin(), tickets.end());
	dfs(0, "ICN", tickets);
	return result;
}

int main() {
	//vector<vector<string>> tickets = { {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL","SFO"} };
	//vector<vector<string>> tickets = { {"ICN", "JFK"},{"HND", "IAD"},{"JFK", "HND"} };
	vector<vector<string>> tickets = { {"ICN", "A"}, {"A", "C"}, {"A", "B"}, {"C", "A"}, {"B","D"} };
	vector<string> answer = solution(tickets);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";

	return 0;
}