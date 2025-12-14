class Solution {
public:
using ll = long long;
    int sumFourDivisors(vector<int>& nums) {
        vector<pair<ll, ll>>divisor(1e5 + 1, {0, 0});
        for(ll i = 1; i <= 1e5; i++){
            for(ll j = i; j <= 1e5; j += i){
                divisor[j].first += 1;
                divisor[j].second += i;
            }
        }
        int n = nums.size();
        int ans = 0;
        for(auto i : nums){
            if(divisor[i].first == 4){
                ans += divisor[i].second;
            }
        }
        return ans;
    }
};