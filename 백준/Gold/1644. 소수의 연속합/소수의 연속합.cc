#include <iostream>
#include <vector>
using namespace std;

int n, s, e, sum, ret;
bool che[4000001];
vector<int> number;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (che[i]) continue;
		for (int j = 2 * i; j <= n; j += i) che[j] = 1;
	}
	for (int i = 2; i <= n; i++) if (!che[i]) number.push_back(i);
	while (1) {
		if (sum >= n) sum -= number[s++];
		else if (e == number.size()) break;
		else sum += number[e++];
		if (sum == n) ret++;
	}
	cout << ret << '\n';
}