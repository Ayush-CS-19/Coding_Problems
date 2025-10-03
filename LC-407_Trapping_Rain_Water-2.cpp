class Solution {
public:
#define P pair<int,pair<int,int>> 
    int trapRainWater(vector<vector<int>>& heights) {
       int vol = 0;
        const int M = heights.size(), N = heights[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<P,vector<P>,greater<P>>pq;
        for(int i = 0; i < N; i++) {
            pq.push({heights[0][i],{ 0, i}}),
            pq.push({heights[M-1][i],{M-1, i}});
            visited[0][i] = true, visited[M-1][i] = true;
        }
        for(int i = 0; i < M; i++) {
            pq.push({heights[i][0],{ i, 0}}),
            pq.push({heights[i][N-1],{i, N-1}});
            visited[i][0] = true, visited[i][N-1] = true;
        }
            
        while(!pq.empty()) {
           auto top = pq.top();
           auto height = top.first;
           auto row = top.second.first;
           auto col = top.second.second;
            pq.pop();
            for(auto dir: directions) {
                int r = row + dir[0], c = col + dir[1];
                if(r >= 0 && r < M && c >= 0 && c < N && !visited[r][c]) {
                    visited[r][c] = true;
                    if(heights[r][c] < height)
                        vol += height - heights[r][c];
                    
                    pq.push({max(height,heights[r][c]),{ r, c}});
                }
            }
        }
        return vol;
    }
};