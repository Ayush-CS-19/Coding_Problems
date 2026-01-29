#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    using T = pair<ll, char>;
    unordered_map<string,ll>dp;
    ll dijkstra(char src, char target,
                unordered_map<char, vector<pair<char,ll>>>& adj) {

        priority_queue<T, vector<T>, greater<T>> pq;
        unordered_map<char, ll> dist;

        for(char c = 'a'; c <= 'z'; c++)
            dist[c] = LLONG_MAX;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            auto [wt, ch] = pq.top();
            pq.pop();

            if(ch == target) return wt;

            if(wt > dist[ch]) continue;

            for(auto &edge : adj[ch]) {
                char nxt = edge.first;
                ll cost = edge.second;

                if(wt + cost < dist[nxt]) {
                    dist[nxt] = wt + cost;
                    pq.push({wt + cost, nxt});
                }
            }
        }
        return -1;
    }

    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        unordered_map<char, vector<pair<char,ll>>> adj;

        for(int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        ll ans = 0;

        for(int i = 0; i < source.size(); i++) {
            if(source[i] != target[i]) {
                string key = to_string(source[i]) + 'X' + to_string(target[i]);
                ll c = 0;
                if(dp.find(key) != dp.end()){
                    c = dp[key];
                }
                else{
                c = dijkstra(source[i], target[i], adj);
                if(c == -1) return -1;
                dp[key] = c;
                }
                ans += c;
            }
        }
        return ans;
    }
};
