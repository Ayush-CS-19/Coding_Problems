#include<bits/stdc++.h>
using namespace std;

int main(){
    int numBot, numExchange;
    cin >> numBot >> numExchange;
    int ans = 0;
    ans += numBot;
    while(numBot >= numExchange){
        int rem = numBot % numExchange;
        numBot /= numExchange;
        ans += numBot;
        numBot += rem;
    }
    cout << ans << " ";
    return 0;
}