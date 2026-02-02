class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
            for(int j = 1; j < n - 1; j++){
                for(int k = j + 1; k < n; k++){
                    int sum = nums[0] + nums[j] + nums[k];
                    ans = min(ans, sum);
                }
        }
        return ans;
    }
};