#include<bits/stdc++.h>
using namespace std;
#define LL long long;
int Solve(vector<int>&height){
    //  0   1   2  3  4  5  6  7  8
    // [1 , 8 , 6, 2, 5, 4, 8, 3, 7]
    int n = height.size();
    int ans = 0;
    int left = 0;
    int right = n - 1;
    while(left < right){
        int mini = min(height[left], height[right]);
        int len = right - left;
        ans = max(ans, mini * len);
        if(height[left] < height[right]){
            left++;
        }
        else{
            right--;
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> heights(n, 0);
    for (int i = 0; i < n; i++)
        cin >> heights[i];
    cout << Solve(heights) << endl;
    return 0;
}