#include<bits/stdc++.h>
using namespace std;

#define LL long long

vector<vector<int>>ans;
bool check =false;
vector<pair<int,int>>dir = {{1,2},{-1, 2},{2,1},{2,-1},{-1,-2},{-2,-1},{1, -2},{-2, 1}};
void Solve(vector<vector<int>>& grid, int i, int j, int idx){
    if(check == true)return;
    if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || grid[i][j] != -1)return;
    grid[i][j] = idx;
    if(idx == (grid.size() * grid.size()) - 1){
        ans = grid;
        check = true;
        return;
    }
    for(auto [x, y] : dir){
        int px = x + i;
        int py = y + j;
        Solve(grid, px, py, idx + 1);
    }
    grid[i][j] = -1;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>grid(n , vector<int>(n, -1));
    ans.resize(n,vector<int>(n, 0));
    Solve(grid, 0, 0, 0);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}