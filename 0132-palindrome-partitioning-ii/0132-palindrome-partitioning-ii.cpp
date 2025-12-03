class Solution {
public:
    vector<int> dp;
    vector<vector<int>> pal;
    int helper(string& s, int i) {
        if (i >= s.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int take = INT_MAX;
        for (int j = i; j < s.size(); j++) {
            if (pal[i][j]) {
                take = min(take, 1 + helper(s, j + 1));
            }
        }
        return dp[i] = take;
    }
    int minCut(string s) {
        int n = s.size();
        pal.assign(n + 1, vector<int>(n + 1, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (len == 1)
                    pal[i][j] = true;
                else if (len == 2)
                    pal[i][j] = (s[i] == s[j]);
                else
                    pal[i][j] = (s[i] == s[j] && pal[i + 1][j - 1]);
            }
        }
        dp.assign(s.size() + 1, -1);
        return helper(s, 0) - 1;
    }
};