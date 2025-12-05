class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prefix(n , 0);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = nums[i] + prefix[i - 1];
        }
        int ans = 0;
        for(int i = 1; i < n; i++){
            int diff = abs(prefix[i - 1] - (prefix[n - 1] - prefix[i - 1]));
           if(diff % 2 == 0)ans++;
        }
        return ans;
    }
};