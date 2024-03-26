#include <iostream>
#include <map>
using namespace std;
int t, n;

int mbti(string a, string b) {
	int res = 0;
	for (int i = 0; i < 4; i++) {
		if (a[i] != b[i]) res++;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while (t--) {
		map<string, int> mp;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string str; cin >> str;
			mp[str]++;
		}
		int res = 100004;
		for (auto i : mp) {
			if (i.second > 2) {
				res = 0;
				break;
			}
			else if (i.second == 2) {
				for (auto j : mp) {
					if (j.first == i.first) continue;
					if (j.second > 2) continue;
					int num = mbti(i.first, j.first) * 2;
					res = min(res, num);
				}
			}
			else {
				for (auto j : mp) {
					if (j.first == i.first) continue;
					if (j.second > 1) continue;
					int num = mbti(i.first, j.first);
					if (num >= res) continue;
					for (auto k : mp) {
						if (k.second > 1) continue;
						if (i.first == k.first || j.first == k.first) continue;
						num = mbti(i.first, j.first);
						num += mbti(i.first, k.first) + mbti(j.first, k.first);
						res = min(res, num);
					}
				}
			}
		}
		cout << res << '\n';
	}
}