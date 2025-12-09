class Solution {
public:
    int mod = 1e9 + 7;

    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;

        // Collect positions of each number
        for (int i = 0; i < n; i++)
            pos[nums[i]].push_back(i);

        long long ans = 0;

        for (auto &p : pos) {
            int x = p.first;
            vector<int>& arr2 = p.second; 

            int big = x * 2;
            if (!pos.count(big)) continue;

            vector<int>& arr1 = pos[big];

            for (int jpos : arr2) {

                int left = lower_bound(arr1.begin(), arr1.end(), jpos) - arr1.begin();


                int right = arr1.end() - upper_bound(arr1.begin(), arr1.end(), jpos);

                ans = (ans + 1LL * left * right) % mod;
            }
        }

        return ans % mod;
    }
};
