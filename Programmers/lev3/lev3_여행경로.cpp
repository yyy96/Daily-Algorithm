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
	if (!result.empty()) return; //���ĵ� ���¿����� ù ����� ��������̴�. (����ġ��-�ð�����)
	if (lev == tickets.size()) {
		path.push_back(start);   //������ ��� �־��ֱ�
		finalRoot();
		return;
	}

	for (int i = 0; i < tickets.size(); i++) {
		if (start != tickets[i][0]) continue; //���� ������� Ƽ���ΰ�
		if (used[i] == 1) continue; //���� �� Ƽ���� ����ߴ°�
		path.push_back(start);
		used[i] = 1;
		dfs(lev + 1, tickets[i][1], tickets);
		used[i] = 0;        //�� �� �߱Ⱑ �ȵ� ��� �ٽ� return
		path.pop_back();    //�־��־��� ��ε� �ٽ� ����
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