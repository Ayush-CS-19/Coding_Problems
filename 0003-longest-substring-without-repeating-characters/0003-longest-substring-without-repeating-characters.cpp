class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())return 0;
        int i = 0;
        int j = 0, n = s.size();
        unordered_map<char, int>mpp;
        int ans = 1;
        while(j < n){
            mpp[s[j]]++;
            while(i < j && mpp[s[j]] >= 2){
                mpp[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};