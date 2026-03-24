class Solution {
public:
    int MOD = 12345;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> arr;
        for (auto &row : grid) {
            for (auto &x : row) {
                arr.push_back(x);
            }
        }

        int size = arr.size();
        vector<long long> prefix(size, 1), suffix(size, 1);


        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % MOD;
        }


        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % MOD;
        }

        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < size; i++) {
            long long prod = (prefix[i] * suffix[i]) % MOD;
            ans[i / m][i % m] = prod;
        }

        return ans;
    }
};