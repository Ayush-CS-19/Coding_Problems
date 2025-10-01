#include<bits/stdc++.h>
using namespace std;
// unordered_set<string> st;
// void Permute(string& s, int i, int n){
//     if(i == n - 1){
//         st.insert(s);
//         return;
//     }
//     for (int j = 0; j < n; j++){
//         swap(s[i], s[j]);
//         Permute(s, i + 1, n);
//         swap(s[i], s[j]);
//     }
//     return;
// }

int main(){
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        do{
            ans.push_back(arr);
        }while(next_permutation(arr.begin(),arr.end()));
        for(auto i : ans){
            for(auto j : i){
                cout << j << " ";
            }
            cout << endl;
        }
        return 0;
}