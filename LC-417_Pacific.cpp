#include<bits/stdc++.h>
using namespace std;

#define LL long long

void BFS(vector<vector<int>>& h,vector<vector<bool>>&v,queue<pair<int,int>>& q){
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int r = front.first;
        int c = front.second;
        v[r][c] = true;
        if(r - 1 >= 0 && v[r - 1][c] != true && h[r-1][c] >= h[r][c]){
            v[r-1][c] = true;
            q.push({r-1,c});
        }
        if(c - 1 >= 0 && v[r][c - 1] != true && h[r][c - 1] >= h[r][c]){
            v[r][c - 1] = true;
            q.push({r,c - 1});
        }
        if(r + 1 < h.size() && v[r + 1][c] != true && h[r + 1][c] >= h[r][c]){
            v[r + 1][c] = true;
            q.push({r + 1,c});
        }
        if(c + 1 < h[0].size() && v[r][c + 1] != true && h[r][c + 1] >= h[r][c]){
            v[r][c + 1] = true;
            q.push({r,c + 1});
        }
    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>>v1(n,vector<bool>(m,false));
        vector<vector<bool>>v2(n,vector<bool>(m,false));
        vector<vector<int>>ans;
        queue<pair<int,int>>q1;
        queue<pair<int,int>>q2;
        for(int i = 0; i < n; i++){
            q1.push({i,0});
            v1[i][0] = true;
        }
        for(int i = 0; i < m; i++){
            q1.push({0,i});
            v1[0][i] = true;
        }
        for(int i = 0; i < n; i++){
            q2.push({i,m - 1});
            v2[i][m-1] = true;
        }
        for(int i = 0; i < m; i++){
            q2.push({n - 1, i});
            v2[n-1][i] = true;
        }
        BFS(heights,v1,q1);
        BFS(heights,v2,q2);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v1[i][j] == true && v2[i][j] == true){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>>ans = pacificAtlantic(arr);
    return 0;
}