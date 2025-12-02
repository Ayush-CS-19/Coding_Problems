class TreeAncestor {
public:
int max;
vector<vector<int>>dp;
void Build(int n, vector<int>& parent){
    max = 17;
    dp.resize(max,vector<int>(n, -1));
    for(int i = 0; i < n; i++){
        dp[0][i] = parent[i];
    }
    for(int i = 1; i < max; i++){
        for(int j = 0; j < n; j++){
            int mid = dp[i - 1][j];
            dp[i][j] = mid == -1 ? -1 : dp[i - 1][mid]; 
        }
    }
}
    TreeAncestor(int n, vector<int>& parent) {
        Build(n, parent);
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i < max && node != -1; i++){
            int mask = (1 << i);
            if((k & mask) > 0){
                node = dp[i][node];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */