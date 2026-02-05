class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        // CREATE AN ARRAY
        int n = nums.size();
        vector<int>ans(n, 0);
        // RULES
        for(int i = 0; i < n; i++){
        int steps = abs(nums[i]) % n;
        int val = 0;
        // 1. nums[i] > 0 move the nums[i] to right.
        if(nums[i] > 0){
            int idx = (i + steps) % n;
            val = nums[idx];
        }
        // 2. nums[i] < 0 move the nums[i] to left.
        else if(nums[i] < 0){
            int idx = (i - steps + n) % n;
            val = nums[idx];
        }
        // 3. nums[i] == 0 then result[i] = num[i]
        else{
            val = nums[i];
        }
        ans[i] = val;
        }
        return ans;
    }
};