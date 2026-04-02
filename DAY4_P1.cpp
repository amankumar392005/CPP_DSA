class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>> rev(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            rev[v].push_back({u, w});
        }

        const int INF = 1e9;
        vector<int> dist(n, INF);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int cost = it.first;
            int node = it.second;

            if (cost > dist[node]) continue;

            for (auto &nbr : rev[node]) {
                int nextNode = nbr.first;
                int wt = nbr.second;

                int newCost = max(cost, wt);

                if (newCost < dist[nextNode]) {
                    dist[nextNode] = newCost;
                    pq.push({newCost, nextNode});
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (dist[i] == INF) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};