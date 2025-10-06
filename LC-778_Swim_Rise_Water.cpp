#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define T pair<int, pair<int,int>>
vector<vector<int>>matrix;
vector<pair<int,int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }

    priority_queue<T,vector<T>,greater<T>>pq;
    matrix.resize(n,vector<int>(m,INT_MAX));
    matrix[0][0] = grid[0][0];
    pq.push({grid[0][0],{0,0}});
    while(!pq.empty()){
        auto [weight , cord] = pq.top();
        pq.pop();
        auto [x , y] = cord;
        for(auto [dx, dy] : dir){
        int px = x + dx;
        int py = y + dy;
        if(px < 0 || py < 0 || px >= n || py >= m) continue;

        int newWeight = max(weight, grid[px][py]);
        if(matrix[px][py] > newWeight){
            matrix[px][py] = newWeight;
            pq.push({newWeight, {px, py}});
        }
        }
    }
    cout<<matrix[n - 1][m - 1]<<endl;
    return 0;
}