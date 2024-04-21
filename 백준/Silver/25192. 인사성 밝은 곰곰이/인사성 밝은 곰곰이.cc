#include <iostream>
#include <map>
using namespace std;

int n, res;
string input;
map<string, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	while (n--) {
		cin >> input;
		if (input == "ENTER") {
			mp.clear(); continue;
		}
		else if (mp[input]) continue;
		mp[input] = 1;
		res++;
	}
	cout << res << "\n";
}