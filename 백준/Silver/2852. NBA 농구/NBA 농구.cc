#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	int t1 = 0, t2 = 0;
	int now = 0;
	int curT = 0, prevT = 0;
	for (int i = 0; i < T; i++) {
		int w;
		string t;
		cin >> w >> t;
		curT = atoi(t.substr(0, 2).c_str()) * 60
			+ atoi(t.substr(3, 5).c_str());
		if (now > 0) {
			t1 += curT - prevT;
		}
		else if (now < 0) {
			t2 += curT - prevT;
		}
		if (w == 1) now++;
		else now--;
		prevT = curT;
	}
	if (now > 0) {
		t1 += 2880 - prevT;
	}
	else if (now < 0) {
		t2 += 2880 - prevT;
	}
	printf("%02d:%02d\n", t1 / 60, t1 % 60);
	printf("%02d:%02d\n", t2 / 60, t2 % 60);
}