class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long total_sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                total_sum += grid[i][j];
            }
        }
        long long t1 = total_sum;
        if(total_sum % 2 != 0)return false;
        long long new_sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                new_sum += grid[i][j];
                total_sum -= grid[i][j];
            }
            if(new_sum == total_sum)return true;
        }
        new_sum = 0;
        total_sum = t1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                new_sum += grid[j][i];
                total_sum -= grid[j][i];   
            }
            if(new_sum == total_sum)return true;
        }
        return false;
    }
};