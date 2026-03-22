class Solution {
public:

unordered_map<string, long long>dp;

long long helper(vector<int>& nums, int target, int idx, int val){
    if(idx >= nums.size()){
        if(val == target)return 0;
        return INT_MAX;
    }
    string key = to_string(idx) + 'X' + to_string(val);
    if(dp.find(key) != dp.end())return dp[key];
    long long take = helper(nums, target, idx + 1, val ^ nums[idx]);
    long long skip = 1 + helper(nums, target, idx + 1, val);
    return dp[key] = min(take, skip);
}

    int minRemovals(vector<int>& nums, int target) {
        int ans = helper(nums, target, 0, 0);
        return ans == INT_MAX ? -1 : ans;
    }
};