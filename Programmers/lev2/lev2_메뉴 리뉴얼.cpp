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

//XY = YX ���� �޴�
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

//lev = ��ǰ�޴����� ����
//branch = �ֹ��� ��� �ڽ� ����
//map = key:�ڽ� ���� value:�ٸ� �ֹ��鿡���� �ش�Ǵ� ������ ��
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

	//2���̻� �ֹ��� �޴���
	for (auto i = result.begin(); i != result.end(); ++i) {
		if (i->second < 2) continue;
		menu.push_back({ i->first, i->second });
	}
	sort(menu.begin(), menu.end(), comp);

	//�ִ� �ֹ��� �޴��� ä��
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
	//bc �� �ȵǴ� ����) ac�� 4�� �ֹ��ߴµ� bc�� 2�� �ֹ��ؼ� = �ִ� ���� �ֹ��Ѱ͸�(���� 2��)
	//bcfg, acde �Ǵ� ����) �� �� 2���� �ֹ��ؼ� �� �� �ִ� �ֹ��� �ش�
	vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
	vector<int> course = { 2,3,4 };
	vector<string> answer = solution(orders, course);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
}