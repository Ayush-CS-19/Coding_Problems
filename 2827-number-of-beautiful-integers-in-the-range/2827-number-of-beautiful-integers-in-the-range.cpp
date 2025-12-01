class Solution {
public:
    using ll = long long;

    // dp[pos][even][odd][rem][started][tight]
    ll dp[12][11][11][21][2][2];

    ll solve(string &s, int idx, int even, int odd, int rem,
             int started, int tight, int k) {

        if (idx == s.size()) {
            return (started && even == odd && rem == 0);
        }

        if (dp[idx][even][odd][rem][started][tight] != -1)
            return dp[idx][even][odd][rem][started][tight];

        int limit = tight ? (s[idx] - '0') : 9;
        ll ans = 0;

        for (int d = 0; d <= limit; d++) {

            int ntight = tight && (d == limit);

            if (!started && d == 0) {
                // Still leading zeros → do not count any digits or remainder
                ans += solve(s, idx + 1, even, odd, rem,
                             0, ntight, k);
            } else {
                // Real digit
                int ne = even + (d % 2 == 0);
                int no = odd + (d % 2 == 1);
                int nrem = (rem * 10 + d) % k;

                ans += solve(s, idx + 1, ne, no, nrem,
                             1, ntight, k);
            }
        }

        return dp[idx][even][odd][rem][started][tight] = ans;
    }

    ll countUpto(ll x, int k) {
        if (x < 0) return 0;

        string s = to_string(x);
        memset(dp, -1, sizeof(dp));

        return solve(s, 0, 0, 0, 0, 0, 1, k);
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        return countUpto(high, k) - countUpto(low - 1, k);
    }
};
