class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        mpp = {}
        for i in text:
            mpp[i] = mpp.get(i, 0) + 1
        ans = 1e9
        check = "balloon"
        for i in check:
            if(i == 'l' or i == 'o'):
                ans = min(ans, mpp.get(i, 0)//2)
            else:
                ans = min(ans, mpp.get(i, 0))
        return ans   