#include<bits/stdc++.h>
using namespace std;

  vector<string> ans;

    void dfs(string &s, int target, int idx, long long curVal, long long lastVal, string expr) {
        if (idx == s.size()) {
            if (curVal == target) {
                ans.push_back(expr);
            }
            return;
        }
        for (int j = idx; j < s.size(); j++) {
            if (j > idx && s[idx] == '0') break;
            string part = s.substr(idx, j - idx + 1);
            long long num = stoll(part);

            if (idx == 0) {
                dfs(s, target, j + 1, num, num, part);
            } else {
                dfs(s, target, j + 1, curVal + num, num, expr + "+" + part);
                dfs(s, target, j + 1, curVal - num, -num, expr + "-" + part);
                dfs(s, target, j + 1, curVal - lastVal + lastVal * num, lastVal * num, expr + "*" + part);
            }
        }
    }
    vector<string> findExpr(string &s, int target) {
        ans.clear();
        dfs(s, target, 0, 0, 0, "");
        sort(ans.begin(), ans.end());
        return ans;
        
    }

    int main(){
        string s;
        int target;
        vector<string> k = findExpr(s, target);
        for(auto i : k){
            cout << i << " ";
        }
        return 0;
    }