#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dep, par, tin, tout;
    long long mod = 1000000007;
    int tim = 0;

    long long power(long long a, long long b) {
        if (b < 0) return 0;

        long long res = 1;
        a %= mod;

        while (b > 0) {
            if (b & 1)
                res = (res * a) % mod;

            a = (a * a) % mod;
            b >>= 1;
        }

        return res;
    }

    void dfs(vector<vector<int>>& g, int node, vector<int>& vis, int d) {
        vis[node] = 1;
        dep[node] = d;
        tin[node] = ++tim;

        for (int child : g[node]) {
            if (!vis[child]) {
                par[child] = node;
                dfs(g, child, vis, d + 1);
            }
        }

        tout[node] = ++tim;
    }

    bool check(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v) {
        if (dep[u] > dep[v])
            swap(u, v);

        int temp = u;

        while (temp > 1) {
            if (check(temp, v))
                return temp;
            temp = par[temp];
        }

        return 1;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        vector<vector<int>> g(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        par.assign(n + 1, 0);
        dep.assign(n + 1, 0);
        tin.assign(n + 1, 0);
        tout.assign(n + 1, 0);

        vector<int> vis(n + 1, 0);

        dfs(g, 1, vis, 0);

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            int ancestor = lca(u, v);
            int dis = dep[u] + dep[v] - 2 * dep[ancestor];

            ans.push_back((int)power(2, dis - 1));
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n; 

    vector<vector<int>> edges(n - 1, vector<int>(2));

    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));

    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution sol;
    vector<int> ans = sol.assignEdgeWeights(edges, queries);

    for (int x : ans) {
        cout << x << '\n';
    }

    return 0;
}