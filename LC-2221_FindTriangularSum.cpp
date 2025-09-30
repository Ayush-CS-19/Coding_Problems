#include<bits/stdc++.h>
using namespace std;
// int rec(vector<int>&arr){
//     if(arr.size() == 1)return arr[0];
//     int n = arr.size();
//     vector<int> newNums(n - 1);
//     for (int i = 0; i < n - 1; i++){
//         newNums[i] = (arr[i] + arr[i + 1]) % 10;
//     }
//     arr.assign(newNums.begin(), newNums.end());
//     return rec(arr);
// }

int Solve(vector<int>&nums){
    // return rec(nums);
    int n = nums.size();
    for (int size = n; size > 1; --size) {
        for (int i = 0; i < size - 1; ++i) {
            nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0];
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout<<Solve(arr)<<endl;
    return 0;
}