class Solution {
public:
    unordered_map<int,long long> dp;

    long long helper(
        string &s, string &t,
        vector<vector<long long>>& dist,
        unordered_map<string,int>& id,
        set<int>& lens,
        int idx
    ){
        if(idx==s.size()) return 0;
        if(dp.count(idx)) return dp[idx];

        long long ans = LLONG_MAX;

        if(s[idx]==t[idx]){
            ans = helper(s,t,dist,id,lens,idx+1);
        }

        for(int len: lens){
            if(idx+len<=s.size()){
                string a = s.substr(idx,len);
                string b = t.substr(idx,len);

                if(id.count(a) && id.count(b)){
                    long long c = dist[id[a]][id[b]];
                    if(c==LLONG_MAX) continue;

                    long long rest = helper(s,t,dist,id,lens,idx+len);
                    if(rest==LLONG_MAX) continue;

                    ans = min(ans, c+rest);
                }
            }
        }
        return dp[idx]=ans;
    }

    long long minimumCost(
        string source, string target,
        vector<string>& original,
        vector<string>& changed,
        vector<int>& cost
    ){
        unordered_map<string,int> id;
        vector<string> nodes;

        auto getId = [&](string s){
            if(!id.count(s)){
                id[s]=nodes.size();
                nodes.push_back(s);
            }
            return id[s];
        };

        for(int i=0;i<original.size();i++){
            getId(original[i]);
            getId(changed[i]);
        }

        int n = nodes.size();
        vector<vector<long long>> dist(n, vector<long long>(n,LLONG_MAX));

        for(int i=0;i<n;i++) dist[i][i]=0;

        for(int i=0;i<original.size();i++){
            int u=getId(original[i]);
            int v=getId(changed[i]);
            dist[u][v]=min(dist[u][v],(long long)cost[i]);
        }

        // Floyd Warshall
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX)
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

        set<int> lens;
        for(auto &s: original) lens.insert(s.size());

        long long res = helper(source,target,dist,id,lens,0);
        return res==LLONG_MAX ? -1 : res;
    }
};
