class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int helper(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if(i == n || j == m)
            return INT_MIN;  

        if(dp[i][j] != INT_MIN)
            return dp[i][j];

        int take = nums1[i] * nums2[j];
        int next = helper(nums1, nums2, i+1, j+1);
        if(next > 0) take += next;

        int skip1 = helper(nums1, nums2, i+1, j);
        int skip2 = helper(nums1, nums2, i, j+1);

        return dp[i][j] = max({take, skip1, skip2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        dp.assign(n, vector<int>(m, INT_MIN));
        return helper(nums1, nums2, 0, 0);
    }
};
