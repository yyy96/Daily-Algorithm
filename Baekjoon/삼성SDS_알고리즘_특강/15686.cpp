#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

//���� �Ｚ ��ä ����
//�ִ� M���� ���� = ����
//�ִ� �Ÿ��� ���϶�������, ��� �� �� �ִ� ��츦 �����ؼ� �Ÿ��� abs�̴ϱ�.
//���� ����� ġŲ���� ����. �� �� BFS

struct Node {
	int x, y;
};
int n, m;
int arr[51][51];
vector<Node> home;
vector<Node> store;
Node path[14];
int used[14];
int minRoad = 21e8;


int checkDistance() {
	int chickenRoadTotal = 0;
	for (int j = 0; j < home.size(); j++) {
		int chickenRoad = 21e8;
		for (int i = 0; i < m; i++) {
			int distance = abs(home[j].x - path[i].x) + abs(home[j].y - path[i].y);
			if (chickenRoad > distance)
				chickenRoad = distance;
		}
		chickenRoadTotal += chickenRoad;
	}
	return chickenRoadTotal;
}

void fun(int lev, int start) {
	if (lev == m) {
		int chickenRoad = checkDistance();
		if (chickenRoad < minRoad) minRoad = chickenRoad;
		return;
	}

	for (int i = start; i < store.size(); i++) { //i=0 �����Ͻ� �ð��ʰ�
		if (used[i] == 1) continue;
		path[lev] = store[i];
		used[i] = 1;
		fun(lev + 1, i+1); //start +1 �ƴ�
		used[i] = 0;
		path[lev] = {};
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				home.push_back({ i,j });
			else if (arr[i][j] == 2)
				store.push_back({ i,j });
		}
	}

	fun(0, 0);

	cout << minRoad;

	return 0;
}