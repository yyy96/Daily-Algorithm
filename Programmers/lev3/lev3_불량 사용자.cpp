#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

set<int> cnt;

bool check(string id, string ban) {
	if (id.length() != ban.length()) return false;
	for (int i = 0; i < id.length(); i++) {
		if (id[i] != ban[i] && ban[i] != '*') return false;
	}
	return true;
}

void dfs(int lev, int used, vector<string> id, vector<string> ban) {
	//lev: ban�� ����
	if (lev == ban.size()) {
		cnt.emplace(used); //����� idx(1,3,4) �鿡 ���� bitmap�� set(map)���� boolüũ ���ش�.
		return;
	}

	//branch: id�� ����
	for (int i = 0; i < id.size(); i++) {
		if (used == (used | (1 << i))) continue; //���� ����� id���� idx�� bitmap���� üũ�Ѵ�
		if (!check(id[i], ban[lev])) continue; //ban�� �ش�Ǵ� id�ΰ�?
		dfs(lev + 1, used | (1 << i), id, ban);
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	dfs(0, 0, user_id, banned_id);
	return cnt.size();
}

int main() {
	vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	vector<string> banned_id = { "fr*d*", "abc1**" };
	cout << solution(user_id, banned_id);
	return 0;
}