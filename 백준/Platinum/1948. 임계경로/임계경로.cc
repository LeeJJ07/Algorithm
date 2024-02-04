#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<pair<int, int>>> A(N + 1);
	vector<vector<pair<int, int>>> reverseA(N + 1);
	vector<int> indegree(N + 1);

	for (int i = 0; i < M; i++) {
		int S, E, V;
		cin >> S >> E >> V;
		A[S].push_back(make_pair(E, V));
		reverseA[E].push_back(make_pair(S, V));
		indegree[E]++;
	}

	int startCity, endCity;
	cin >> startCity >> endCity;
	queue<int> mq;
	mq.push(startCity);
	vector<int> result(N + 1);

	while (!mq.empty()) {
		int now = mq.front();
		mq.pop();
		for (pair<int, int> next : A[now]) {
			indegree[next.first]--;
			result[next.first] = max(result[next.first], result[now] + next.second);
			if (indegree[next.first] == 0) {
				mq.push(next.first);
			}
		}
	}
	int resultCount = 0;
	vector<bool> visited(N + 1);
	queue<int> rq;
	rq.push(endCity);
	visited[endCity] = true;

	while (!rq.empty()) {
		int now = rq.front();
		rq.pop();
		for (pair<int, int> next : reverseA[now]) {
			if (result[next.first] + next.second == result[now]) {
				resultCount++;
				if (!visited[next.first]) {
					visited[next.first] = true;
					rq.push(next.first);
				}
			}
		}
	}
	cout << result[endCity] << "\n";
	cout << resultCount << "\n";
}