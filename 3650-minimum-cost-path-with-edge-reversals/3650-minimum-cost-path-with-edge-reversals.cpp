class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>>mpp;
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            mpp[u].push_back({w,v});
            mpp[v].push_back({2*w, u});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>vis(n, INT_MAX);
        vis[0] = 0;
        while(!pq.empty()){
            auto [weight, edge] = pq.top();
            pq.pop();
            if(weight > vis[edge])continue;
            for(auto node : mpp[edge]){
                auto [w , v] = node;
                if(weight + w < vis[v]){
                    vis[v] = weight + w;
                    pq.push({weight + w, v});
                }
            }
        }
        return vis[n - 1] == INT_MAX ? -1 : vis[n - 1];
    }
};