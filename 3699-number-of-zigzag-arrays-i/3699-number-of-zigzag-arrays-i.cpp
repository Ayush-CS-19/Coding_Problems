class Solution {
public:
    int mod = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<vector<int>>dp(m,vector<int>(2, 0)),dp2(m,vector<int>(2,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                if(i == j)continue;
                if(i < j)dp[j][0] = (dp[j][0] + 1 % mod);
                else dp[j][1] = (dp[j][1] + 1 % mod);
            }
        }
        for(int i = 2; i < n; i++){
            vector<int>prefix1(m + 1, 0),prefix2(m  + 1, 0);
            for(int j = 0; j < m; j++){
                prefix1[j + 1] = (prefix1[j] + dp[j][0]) % mod;
                prefix2[j + 1] = (prefix2[j] + dp[j][1]) % mod;
            }
            for(int k = 0; k < m; k++){
                dp2[k][1] = (prefix1[m] - prefix1[k + 1] + mod) % mod;
                dp2[k][0] = prefix2[k];
            }
            dp.swap(dp2);
        }
        long long ans = 0;
        for(int i = 0; i < m; i++){
            ans = (ans + dp[i][0]) % mod;
            ans = (ans + dp[i][1]) % mod;
        }
        return ans;
    }
};
