class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        set<pair<int,int>>st;
        int n = nums.size();
        for(auto i : nums)mpp[i]++;
        if(k != 0){
        for(int i = 0; i < n; i++){
            int neg = nums[i] - k;
            int pos = nums[i] + k;
            if(mpp.find(neg) != mpp.end()){
                cout<<nums[i]<<" "<<neg<<endl;
                st.insert({min(nums[i], neg), max(nums[i], neg)});
            }
            if(mpp.find(pos) != mpp.end()){
                cout<<nums[i]<<" "<<pos<<endl;
                st.insert({min(nums[i], pos), max(nums[i], pos)});
            }
        }
        }
        else{
            int ans = 0;
            for(auto [i, j] : mpp){
                if(j >= 2)ans++;
            }
            return ans;
        }
        return st.size();
    }
};