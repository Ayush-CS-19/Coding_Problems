#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int n, m;
int mod = 1e9 + 7;
vector<vector<vector<int>>>dp;
int Solve(vector<vector<int>>& grid, int i, int j, int sum, int& k){
    if(i >= n || j >= m)return 0;
    if(i == n - 1 && j == m - 1){
        if((sum + grid[i][j]) % k == 0)return 1;
        return 0;
    }
    if(dp[i][j][sum] != -1)return dp[i][j][sum];
    int down = Solve(grid, i + 1, j, (sum + grid[i][j]) % k, k);
    int right = Solve(grid, i, j + 1, (sum + grid[i][j]) % k, k);
    return dp[i][j][sum] = (down + right) % mod;
}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        dp.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        return Solve(grid, 0, 0, 0, k);
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }

    int k;
    cin>>k;
    Solution A;
    cout<<A.numberOfPaths(grid, k)<<endl;
    return 0;
}