class Solution {
public:
    int n, k;
    vector<int> graph[15];
    vector<int> dp;

    int helper(int mask) {
        if (mask == (1 << n) - 1)
            return 0;

        if (dp[mask] != -1)
            return dp[mask];

        vector<int> indeg(n, 0);

        // Build indegree based on NOT taken nodes
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) {
                for (int v : graph[u]) {
                    if (!(mask & (1 << v)))
                        indeg[v]++;
                }
            }
        }

        // Build available mask
        int avail_mask = 0;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0 && !(mask & (1 << i)))
                avail_mask |= (1 << i);
        }

        int num_avail = __builtin_popcount(avail_mask);
        int best = INT_MAX;

        if (num_avail <= k) {
            best = 1 + helper(mask | avail_mask);
        } else {
            int m = avail_mask;
            for (int sub = m; sub; sub = (sub - 1) & m) {
                if (__builtin_popcount(sub) == k)
                    best = min(best, 1 + helper(mask | sub));
            }
        }

        return dp[mask] = best;
    }

    int minNumberOfSemesters(int N, vector<vector<int>>& relations, int K) {
        n = N;
        k = K;

        for (int i = 0; i < n; i++)
            graph[i].clear();

        for (auto& x : relations) {
            int pre = x[0] - 1;
            int next = x[1] - 1;
            graph[pre].push_back(next); // DIRECTED
        }

        dp.assign(1 << n, -1);
        return helper(0);
    }
};
