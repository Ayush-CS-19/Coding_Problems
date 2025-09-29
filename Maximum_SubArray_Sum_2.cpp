#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;

int MaximumSubarraySum2(vector<int>&arr, int a, int b){
        int n = arr.size();
        vector<long long>prefix(n + 1, 0);
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }
        deque<int>dq;
        int ans = INT_MIN;
        for(int i = a; i <= n; i++){
            int left = i - a;
            while(!dq.empty() && prefix[dq.back()] >= prefix[left]){
                dq.pop_back();
            }
            dq.push_back(left);
            while(!dq.empty() && dq.front() < i - b){
                dq.front();
            }
            ans = max(ans, (int)(prefix[i] - prefix[dq.front()]));
        }
        return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int a;
    int b;
    cin >> a >> b;
    return 0;
}