class Solution {
public:
int n, m;
unordered_map<string, int>dp;
long long helper(string& s1, string& s2, int i, int j){
    string key = to_string(i) + ',' + to_string(j);
    if(dp.find(key) != dp.end())return dp[key];
    if(i == n){
        long long sum = 0;
        while(j < m)sum += s2[j++];
        return sum;
    }
    if(j == m){
        long long sum = 0;
        while(i < n)sum += s1[i++];
        return sum;
    }
    if(s1[i] == s2[j]){
        return dp[key] = helper(s1, s2, i + 1, j + 1);
    }
    long long del1 = s1[i] + helper(s1, s2, i + 1, j);
    long long del2 = s2[j] + helper(s1, s2, i, j + 1);
    return dp[key] = min(del1, del2);
}
    int minimumDeleteSum(string s1, string s2) {
        int ans = 0;
        n = s1.size(), m = s2.size();
        ans = (int)helper(s1, s2, 0, 0);
        return ans;
    }
};