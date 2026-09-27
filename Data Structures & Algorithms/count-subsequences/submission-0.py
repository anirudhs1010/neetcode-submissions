class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        #
        m = len(t)
        n = len(s)
        
        dp = [0] * (m + 1) 
        dp[0] = 1
        for i in range(1, n+1):
            for j in range(m, 0, -1):
                if t[j-1] == s[i-1]:
                    dp[j] += dp[j-1]
        return dp[m]
    
