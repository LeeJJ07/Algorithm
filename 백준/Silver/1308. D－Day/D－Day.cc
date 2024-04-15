#include <iostream>
using namespace std;

int ty, tm, td, ny, nm, nd;
int day010101(int y, int m, int d) {
	int days = 0;
	for (int i = 1; i < y; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
			days += 366;
		else days += 365;
	}
	int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
		month[1] = 29;
	}
	for (int i = 0; i < m -1; i++) {
		days += month[i];
	}
	return days + d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> ty >> tm >> td >> ny >> nm >> nd;
	int tmp1 = tm * 40 + td, tmp2 = nm * 40 + nd;
	if (ny - ty > 1000 || (ny - ty == 1000 && (tm < nm || (tm == nm && td <= nd)))) cout << "gg\n";
	else {
		int days = day010101(ny, nm, nd) - day010101(ty, tm, td);
		cout << "D-" << days << "\n";
	}
}