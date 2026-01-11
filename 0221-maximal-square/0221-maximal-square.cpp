class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>mat(m, 0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1')mat[j]++;
                else mat[j] = 0;
            }
            vector<int>prev(m, -1);
            vector<int>next(m, m);
            stack<int>st;
            for(int k = 0; k < m; k++){
                while(!st.empty() && mat[st.top()] >= mat[k])st.pop();
                if(!st.empty())prev[k] = st.top();
                st.push(k);
            }
            while(!st.empty())st.pop();
            for(int k = m - 1; k > -1; k--){
                while(!st.empty() && mat[st.top()] >= mat[k])st.pop();
                if(!st.empty())next[k] = st.top();
                st.push(k);
            }
            for(int k = 0; k < m; k++){
                int area = min(next[k] - prev[k] - 1, mat[k]);
                ans = max(ans, area*area);
            }
        }
        return ans;
    }
};