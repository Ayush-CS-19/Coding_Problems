class Solution {
public:
int mod = 1e9 + 7;
    int countPermutations(vector<int>& A) {
        int n = A.size();
        long long ans = 1;
        for(int i = 1; i < n; i++){
            if(A[i] <= A[0]){
                return 0;
            }
            ans = ((ans) % mod * i) % mod;
        }
        return ans;
    }
};