#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int N;
int S;
int arr[100001];
int minLen = 21e8;

void fun() {
	int Start = 0;
	int End = 0;
	int sum = 0;

	while(End<=N) {
		if (sum >= S) {
			if (minLen > End - Start)
				minLen = End - Start;
			sum -= arr[Start];
			Start++;
		}
		else {
			sum += arr[End];
			End++;
		}
	}
}
int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	fun();

	if (minLen == 21e8) cout << "0";
	else cout << minLen;

	return 0;
}