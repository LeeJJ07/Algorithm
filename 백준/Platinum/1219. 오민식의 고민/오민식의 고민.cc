#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> edge;
static int N, M, sCity, eCity;
static vector<long> mdistance, cityMoney;
static vector<edge> edges;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> sCity >> eCity >> M;
	mdistance.resize(N);
	cityMoney.resize(N);
	fill(mdistance.begin(), mdistance.end(), LONG_MIN);

	for (int i = 0; i < M; i++) {
		int start, end, price;
		cin >> start >> end >> price;
		edges.push_back(make_tuple(start, end, price));
	}
	for (int i = 0; i < N; i++) {
		cin >> cityMoney[i];
	}
	mdistance[sCity] = cityMoney[sCity];

	for (int i = 0; i <= N + 50; i++) {
		for (int j = 0; j < M; j++) {
			int start = get<0>(edges[j]);
			int end = get<1>(edges[j]);
			int price = get<2>(edges[j]);

			if (mdistance[start] == LONG_MIN)
				continue;
			else if (mdistance[start] == LONG_MAX)
				mdistance[end] = LONG_MAX;
			else if (mdistance[end] < mdistance[start] + cityMoney[end] - price) {
				mdistance[end] = mdistance[start] + cityMoney[end] - price;
				if (i >= N - 1)
					mdistance[end] = LONG_MAX;
			}
		}
	}
	if (mdistance[eCity] == LONG_MIN)
		cout << "gg" << "\n";
	else if (mdistance[eCity] == LONG_MAX)
		cout << "Gee" << "\n";
	else
		cout << mdistance[eCity] << "\n";
}