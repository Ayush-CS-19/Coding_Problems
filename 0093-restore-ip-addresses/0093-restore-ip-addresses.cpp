class Solution {
public:
    unordered_set<string> st;

    void helper(string &s, int i, string IP, int cnt) {
        if (cnt == 4) {
            if (i == s.size()) {
                IP.pop_back();
                st.insert(IP);
            }
            return;
        }

        if (i >= s.size()) return;

        for (int len = 1; len <= 3 && i + len <= s.size(); len++) {
            string valid = s.substr(i, len);

            if (valid.size() > 1 && valid[0] == '0') break;

            int val = stoi(valid);
            if (val > 255) break;

            helper(s, i + len, IP + valid + '.', cnt + 1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        st.clear();
        helper(s, 0, "", 0);
        return vector<string>(st.begin(), st.end());
    }
};
