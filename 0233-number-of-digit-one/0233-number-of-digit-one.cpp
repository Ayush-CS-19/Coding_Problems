class Solution {
public:
int dp[20][2][20];
int solve(string& s, int idx, int tight, int count){
    if(idx == s.size())return count;
    if(dp[idx][tight][count] != -1)return dp[idx][tight][count];
    int limit = tight == 1 ? s[idx] - '0' : 9;
    int ans = 0;
    for(int i = 0; i <= limit; i++){
        int updateCount = count + (i == 1 ? 1 : 0);
        ans += solve(s, idx + 1,(tight & (i == s[idx] - '0'))  ,updateCount);
    }
    return dp[idx][tight][count] = ans;
}
    int countDigitOne(int n) {
        string r = to_string(n);
        memset(dp, -1, sizeof(dp));
        int rightAns = solve(r, 0, true, 0);
        return rightAns;
    }
};