#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
class Solution {
public:
typedef tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update>set_tree;
    int reversePairs(vector<int>& nums) {
        set_tree st;
        int ans = 0;
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--){
            int cnt1 = st.order_of_key({nums[i], -1});
            ans += cnt1;
            st.insert({1LL * 2*nums[i], i});
        }
        return ans;
    }
};