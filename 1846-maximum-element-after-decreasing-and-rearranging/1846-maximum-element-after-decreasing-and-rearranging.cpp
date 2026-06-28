class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        int n = arr.size();
        for(int i = 1; i < n; i++){
            arr[i] = min(arr[i - 1] + 1, arr[i]);
        }
        return arr[n - 1];
    }
};