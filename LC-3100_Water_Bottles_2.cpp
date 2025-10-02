#include<bits/stdc++.h>
using namespace std;

int main(){
    int Ex, Bo;
    cin >> Bo >> Ex;
    int ans = 0;
    ans += Bo;
    while(Bo >= Ex){
        int new_Bo = 0;
        while(Bo >= Ex){
            Bo -= Ex;
            Ex++;
            new_Bo++;
        }
        ans += new_Bo;
        if(Bo >= 0)
            Bo += new_Bo;
        else
            Bo = new_Bo;
    }
    cout << ans << endl;
    return 0;
}