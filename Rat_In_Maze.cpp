#include<bits/stdc++.h>
using namespace std;

#define LL long long

vector<string>ans;
vector<vector<bool>>visited;
vector<pair<char,pair<int,int>>>dir = {{'D',{1, 0}},{'R',{0, 1}},{'U',{-1, 0}},{'L',{0, -1}}};
void helper(int n, int m, string k, int i, int j, vector<vector<int>>& maze){
    if(i >= n || j >= m || i < 0 || j  < 0 || visited[i][j] == true || maze[i][j] == 0)return;
    if(i == n - 1 && j == m - 1){
        ans.push_back(k);
        return;
    }
    visited[i][j] = true;
    for(auto node : dir){
        char L = node.first; 
        auto [x , y] = node.second;
        helper(n, m, k + L , x + i, y + j, maze);
    }
    visited[i][j] = false;
}
vector<string>Solve(vector<vector<int>>& maze){
    int n = maze.size();
    int m = maze[0].size();
    visited.resize(n, vector<bool>(m,false));
    helper(n, m, "", 0, 0, maze);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> maze(n,vector<int>(m,0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
                cin>>maze[i][j];
    vector<string>arr = Solve(maze);
    return 0;
}