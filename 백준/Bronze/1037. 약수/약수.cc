#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, input;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	while (n--) { cin >> input; v.push_back(input); }
	if (n == 1) cout << input * input << '\n';
	else {
		sort(v.begin(), v.end());
		cout << v[0] * v[v.size() - 1] << '\n';
	}
}