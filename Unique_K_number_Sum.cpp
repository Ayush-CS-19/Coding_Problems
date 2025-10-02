#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void Solve(int n, int k, int start, vector<int>& temp, int sum) {
    if (sum > n || temp.size() > k) return;

    if (sum == n && temp.size() == k) {
        ans.push_back(temp);
        return;
    }

    for (int i = start; i <= 9; i++) {
        temp.push_back(i);
        Solve(n, k, i + 1, temp, sum + i); 
        temp.pop_back();
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> temp;
    Solve(n, k, 1, temp, 0);

    for (auto& comb : ans) {
        for (int x : comb) cout << x;
        cout << " ";
    }
    return 0;
}