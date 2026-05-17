#include <bits/stdc++.h>
using namespace std;

// Count minimal vertices to announce so that the topological order becomes unique.
// For every step, if there are multiple zero-indegree choices, we must tell
// which vertex goes there. Counting such steps along the given topological order
// yields the minimum.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	if (!(cin >> T)) return 0;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<vector<int>> g(N + 1);
		vector<int> indeg(N + 1, 0);
		for (int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
			indeg[y]++;
		}

		vector<int> pos_of_vertex(N + 1);
		vector<int> order(N + 1); // 1-indexed order position -> vertex
		for (int v = 1; v <= N; v++) {
			int p;
			cin >> p;           // P_v = position of vertex v
			pos_of_vertex[v] = p;
			order[p] = v;
		}

		int zero_cnt = 0;
		for (int v = 1; v <= N; v++) if (indeg[v] == 0) zero_cnt++;

		int answer = 0;
		for (int pos = 1; pos <= N; pos++) {
			int v = order[pos];
			// v should be in the current zero-indegree set because order is a topo sort
			if (zero_cnt > 1) answer++;

			// remove v
			zero_cnt--;
			for (int to : g[v]) {
				if (--indeg[to] == 0) zero_cnt++;
			}
		}

		cout << answer << '\n';
	}

	return 0;
}

