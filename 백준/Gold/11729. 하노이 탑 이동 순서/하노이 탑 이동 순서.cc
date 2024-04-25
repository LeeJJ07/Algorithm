#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int from, int by, int to) {
	//from : 출발지, by : 경유지, to : 목적지
	if (n == 1) cout << from << " " << to << "\n";
	else {
		hanoi(n - 1, from, to, by);
		cout << from << " " << to << "\n";
		hanoi(n - 1, by, from, to);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	int cnt = pow(2, n) - 1;
	cout << cnt << "\n";
	hanoi(n, 1, 2, 3);
}