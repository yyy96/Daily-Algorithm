#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Menu {
	string menu;
	int cnt;
};
unordered_map<string, int> result;

bool comp(Menu a, Menu b) {
	if (a.menu.length() < b.menu.length()) return true;
	if (a.menu.length() > b.menu.length()) return false;
	return a.cnt > b.cnt;
}

//XY = YX 같은 메뉴
string getMenu(string menu) {
	string remenu = "";
	vector<char> m;
	for (int i = 0; i < menu.length(); i++)
		m.push_back(menu[i]);
	sort(m.begin(), m.end());
	for (int i = 0; i < m.size(); i++)
		remenu += m[i];
	return remenu;
}

//lev = 단품메뉴들의 갯수
//branch = 주문의 모든 코스 조합
//map = key:코스 조합 value:다른 주문들에서도 해당되는 조합의 합
void dfs(int lev, int start, string menu, string order, int cnt) {
	if (lev == cnt) {
		result[getMenu(menu)]++;
		return;
	}

	for (int i = start; i < order.length(); i++) {
		dfs(lev + 1, i + 1, menu + order[i], order, cnt);
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	vector<Menu> menu;

	for (int i = 0; i < orders.size(); i++) {
		for (int j = 0; j < course.size(); j++) {
			dfs(0, 0, "", orders[i], course[j]);
		}
	}

	//2번이상 주문된 메뉴들
	for (auto i = result.begin(); i != result.end(); ++i) {
		if (i->second < 2) continue;
		menu.push_back({ i->first, i->second });
	}
	sort(menu.begin(), menu.end(), comp);

	//최대 주문한 메뉴만 채택
	int maxCnt = 0;
	int courseCnt = 0;
	for (int i = 0; i < menu.size(); i++) {
		if (menu[i].menu.length() > courseCnt) {
			maxCnt = menu[i].cnt;
			courseCnt = menu[i].menu.length();
		}
		if (menu[i].cnt >= maxCnt)
			answer.push_back(menu[i].menu);
	}

	sort(answer.begin(), answer.end());
	return answer;
}

int main() {
	//bc 가 안되는 이유) ac는 4번 주문했는데 bc는 2번 주문해서 = 최대 많이 주문한것만(최저 2번)
	//bcfg, acde 되는 이유) 둘 다 2번씩 주문해서 둘 다 최대 주문에 해당
	vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
	vector<int> course = { 2,3,4 };
	vector<string> answer = solution(orders, course);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
}