#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Music {
	int time;
	string name;
	string sound;
};

bool compare(Music a, Music b) {
	return a.time > b.time;
}

int getTime(string musicinfo) {
	int sh = stoi(musicinfo.substr(0, 2));
	int sm = stoi(musicinfo.substr(3, 2));
	int eh = stoi(musicinfo.substr(6, 2));
	int em = stoi(musicinfo.substr(9, 2));
	return 60 * (eh - sh) + (em - sm); //abs 주의 (ex.03:58-04:01)
}

string getName(string musicinfo) {
	int endIdx = musicinfo.find(',', 12);
	return musicinfo.substr(12, endIdx - 12);
}

//토큰화하지 않을 경우 C# -> c 로 치환
string substitute(string sound) {
	int s = 0;
	while (1) {
		int idx = sound.find('#', s);
		if (idx == -1) break;
		sound[idx - 1] = sound[idx - 1] + 32;
		sound.erase(sound.begin() + idx);
		s = idx - 1;
	}
	return sound;
}

string getSound(string musicinfo, string m, int time) {
	int startIdx = musicinfo.find(',', 12);
	string sound = musicinfo.substr(startIdx + 1);
	sound = substitute(sound);

	if (sound.length() > time)
		return sound.substr(0, time);

	while (sound.length() <= time) {
		sound += sound;
	}
	return sound;
}

//출제의도: 부분 문자열 비교를 묻는 문제
string solution(string m, vector<string> musicinfos) {
	string answer = "(None)";
	vector<Music> music;

	for (int i = 0; i < musicinfos.size(); i++) {
		int time = getTime(musicinfos[i]);
		string name = getName(musicinfos[i]);
		string sound = getSound(musicinfos[i], m, time);
		sound = substitute(sound);
		music.push_back({ time, name, sound });
	}
	sort(music.begin(), music.end(), compare);

	m = substitute(m);
	for (int i = 0; i < music.size(); i++) {
		if (music[i].sound.find(m) == -1) continue;
		answer = music[i].name;
		break;
	}
	return answer;
}


int main() {
	string m = "CC#BCC#BCC#BCC#B";
	vector<string> musicinfos = { "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" };
	cout << solution(m, musicinfos);
	return 0;
}