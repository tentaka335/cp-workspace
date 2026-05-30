#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// グラフの型定義（隣接リスト）
using Graph = vector<vector<int>>;

/**
 * 1回目のDFS: 帰りがけ順にスタックへ保存
 */
void dfs1(int v, const Graph &adj, vector<bool> &visited, stack<int> &st)
{
    visited[v] = true;
    for (int next : adj[v])
    {
        if (!visited[next])
            dfs1(next, adj, visited, st);
    }
    st.push(v); // 帰りがけにスタ vector に追加
}

/**
 * 2回目のDFS: 反転グラフ上で探索し、成分を抽出
 */
void dfs2(int v, const Graph &rev_adj, vector<bool> &visited, vector<int> &component)
{
    visited[v] = true;
    component.push_back(v);
    for (int next : rev_adj[v])
    {
        if (!visited[next])
            dfs2(next, rev_adj, visited, component);
    }
}

/**
 * Kosarajuのアルゴリズム本体
 */
vector<vector<int>> get_scc(int n, const Graph &adj)
{
    // 1. グラフを反転させる準備
    Graph rev_adj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int next : adj[i])
        {
            rev_adj[next].push_back(i);
        }
    }

    stack<int> st;
    vector<bool> visited(n + 1, false);

    // 2. 元のグラフでDFS（スタック作成）
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs1(i, adj, visited, st);
    }

    // 3. 反転グラフでDFS
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;

    while (!st.empty())
    {
        int v = st.top();
        st.pop();
        if (!visited[v])
        {
            vector<int> component;
            dfs2(v, rev_adj, visited, component);
            sccs.push_back(component);
        }
    }

    return sccs;
}

int main()
{
    // 頂点数N, 辺数M
    int n, m;
    cin >> n >> m;

    Graph adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // SCCの実行
    vector<vector<int>> sccs = get_scc(n, adj);

    // 結果の出力
    cout << "Number of SCCs: " << sccs.size() << endl;
    for (int i = 0; i < sccs.size(); i++)
    {
        cout << "SCC #" << i + 1 << ": ";
        for (int v : sccs[i])
            cout << v << " ";
        cout << endl;
    }

    return 0;
}