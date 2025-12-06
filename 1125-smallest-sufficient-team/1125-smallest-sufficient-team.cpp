class Solution {
public:
int finish;
unordered_map<string, int>mpp;
vector<int>people_mask;
vector<int>ans;
unordered_map<string, int>dp;
void solve(int idx, vector<int>& temp, int mask){
    if(idx == people_mask.size()){
        if(mask == finish){
            if(ans.size() == 0 || temp.size() <= ans.size()){
                ans = temp;
            }
        }
        return;
    }
    string key = to_string(idx) + ',' + to_string(mask);
    if(ans.size() != 0 && temp.size() >= ans.size())return;
    if(dp.find(key) != dp.end()){
        if(dp[key] <= temp.size())return;
    }
    solve(idx + 1, temp, mask);
    if((mask | people_mask[idx]) != mask){
    temp.push_back(idx);
    solve(idx + 1, temp, mask | people_mask[idx]);
    temp.pop_back();
    dp[key] = (temp.size() != 0) ? temp.size() : -1;
    }
}
    vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                       vector<vector<string>>& people) {
        finish = (1 << req_skills.size()) - 1;
        int n = people.size(), count = 0;
        for (auto x : req_skills) {
            mpp[x] = count;
            count++;
        }
        for(auto &x : people){
            int bit = 0;
            for(string& skill : x){
                bit = bit | (1 << mpp[skill]);
            }
            people_mask.push_back(bit);
        }
        vector<int>temp;
        solve(0, temp, 0);
        return ans;
    }
};