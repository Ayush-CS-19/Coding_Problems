class Solution {
public:
unordered_set<string>st;
string ans = "";
void helper(string& k, int i){
    if(st.find(k) == st.end()){
        ans = k;
        return;
    }
    k[i] = k[i] == '0' ? '1' : '0';
    helper(k, i + 1);
    k[i] = k[i] == '0' ? '1' : '0';
    return;
}
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        for(auto &i : nums)st.insert(i);
        string s = "";
        for(int i = 0; i < n; i++)s += '0';
        helper(s, 0);
        return ans;
    }
};