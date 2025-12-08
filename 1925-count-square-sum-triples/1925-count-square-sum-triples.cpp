class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                for(int k = 1; k <= n; k++){
                    int p = i * i;
                    int q = j * j;
                    int r = k * k;
                    if(p + q == r){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};