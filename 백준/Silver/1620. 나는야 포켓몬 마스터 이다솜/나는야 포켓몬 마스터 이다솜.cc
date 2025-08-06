#include <iostream>
#include <map>
#include <string>

using namespace std;

int n, m, idx;
string temp;
map<int, string> dict1;
map<string, int> dict2;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	while (n--) {
		idx++;
		cin >> temp;
		dict1[idx] = temp;
		dict2[temp] = idx;
	}

	while (m--) {
		cin >> temp;
		if (atoi(temp.c_str()) == 0)
			cout << dict2[temp];
		else
			cout << dict1[atoi(temp.c_str())];
		cout << '\n';
	}
}