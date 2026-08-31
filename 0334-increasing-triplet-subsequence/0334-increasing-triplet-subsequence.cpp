using ll = long long;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    int n = nums.size();
    vector<int>sm(n, 0);
    vector<int>lg(n, 0);
    sm[0] = nums[0];
    lg[n - 1] = nums[n - 1];
    for(ll i = 1; i < n; i++){
        sm[i] = min(sm[i - 1], nums[i]);
    }
    for(ll i = n - 2; i >= 0; i--){
        lg[i] = max(lg[i + 1], nums[i]);
    }

    bool ans = false;

    for(int i = 1; i < n - 1; i++){
        if(sm[i - 1] < nums[i] & nums[i] < lg[i + 1]){
            ans = true;
            break;
        }
    }
    return ans;
  }
};