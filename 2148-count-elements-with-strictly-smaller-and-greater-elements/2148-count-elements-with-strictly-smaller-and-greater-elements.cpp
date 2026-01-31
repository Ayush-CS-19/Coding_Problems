class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for(int i = 1; i < n - 1; i++){
            if(nums[0] < nums[i] && nums[i] < nums[n - 1])ans++;
        }
        return ans;
    }
};