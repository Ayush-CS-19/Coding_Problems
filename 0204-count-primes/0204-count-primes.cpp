class Solution {
public:
using ll = long long;
    int countPrimes(int n) {
        vector<bool>count_prime(n, false);
        if(n == 2)return 0;
        int ans = 0;
        for(ll i = 2; i < n; i++){
            if(count_prime[i] == false)ans++;
            for(ll j = i; j < n; j += i){
                count_prime[j] = true;
            }
        }
        return ans;
    }
};