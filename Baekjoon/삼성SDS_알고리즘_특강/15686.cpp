#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

//실제 삼성 공채 문제
//최대 M개를 골라라 = 조합
//최단 거리를 구하라이지만, 모든 고를 수 있는 경우를 나열해서 거리는 abs이니까.
//가장 가까운 치킨집을 골라라. 일 때 BFS

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

	for (int i = start; i < store.size(); i++) { //i=0 부터일시 시간초과
		if (used[i] == 1) continue;
		path[lev] = store[i];
		used[i] = 1;
		fun(lev + 1, i+1); //start +1 아님
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