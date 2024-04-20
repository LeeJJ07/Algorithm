#include <iostream>
using namespace std;

double N, L, a, i;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> L;
	for (i = L; i <= 100; i++) {
		a  = (2 * N / i - i + 1) / 2;
		if (a == int((2 * N / i - i + 1) / 2) && a >= 0) break;
	}
	if (i == 101) cout << "-1\n";
	else for (int j = a; j < a + i; j++) cout << j << " ";
}