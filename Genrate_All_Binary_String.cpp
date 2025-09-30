#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
void Solve(unordered_set<string>& st, int n, string k){
    if(n <= k.size()){
        st.insert(k);
        return;
    }
    Solve(st, n, k + '1');
    Solve(st, n, k + '0');
    return;
}
int main(){
    int n;
    cin >> n;
    vector<string> ans;
    unordered_set<string> st;
    Solve(st, n, "");
    ans.assign(st.begin(), st.end());
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}