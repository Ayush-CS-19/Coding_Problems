#include<bits/stdc++.h>
using namespace std;
#define LL long long
vector<string> ans;
void helper(vector<int>& arr, unordered_map<int, vector<char>>&mpp, int i, string s){
    if(i >= arr.size()){
        ans.push_back(s);
        return;
    }
    if(arr[i] == 0 || arr[i] == 1){
        helper(arr, mpp, i + 1, s);
    }
    else{
    for(auto k : mpp[arr[i]]){
        s += k;
        helper(arr, mpp, i + 1, s);
        s.pop_back();
    }
}
}
void Solve(vector<int>& arr){
    int n = arr.size();
    unordered_map<int, vector<char>> mpp;
    mpp[2] = {'a', 'b', 'c'};
    mpp[3] = {'d', 'e', 'f'};
    mpp[4] = {'g', 'h', 'i'};
    mpp[5] = {'j', 'k', 'l'};
    mpp[6] = {'m', 'n', 'o'};
    mpp[7] = {'p', 'q', 'r', 's'};
    mpp[8] = { 't', 'u','v'};
    mpp[9] = {'w', 'x', 'y', 'z'};
    helper(arr, mpp, 0, "");
    for(auto i : ans){
        cout << i << " ";
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Solve(arr);
    return 0;
}