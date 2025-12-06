class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps,
                                 vector<vector<int>>& queries) {

        vector<int> ans;
        if (n == 0)
            return ans;

        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        unordered_map<int, int> dag1;
        unordered_map<int, int> dag2;
        set<pair<int, int>> st;

        for (auto& x : lamps) {
            int p = x[0];
            int q = x[1];
            if (!st.count({p, q})) {
                st.insert({p, q});
                mp1[p]++;
                mp2[q]++;
                dag1[p + q]++;
                dag2[p - q]++;
            }
        }

        for (auto& q : queries) {
            int x = q[0];
            int y = q[1];
            if (mp1[x] > 0 || mp2[y] > 0 || dag1[x + y] > 0 ||
                dag2[x - y] > 0) {
                ans.push_back(1);
                for (int j = -1; j <= 1; j++) {
                    for (int k = -1; k <= 1; k++) {
                        int qx = x + j;
                        int qy = y + k;
                        if (qx >= 0 && qx < n && qy >= 0 && qy < n &&
                            st.count({qx, qy})) {
                            st.erase({qx, qy});
                            mp1[qx]--;
                            mp2[qy]--;
                            dag1[qx + qy]--;
                            dag2[qx - qy]--;
                        }
                    }
                }
            } else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};