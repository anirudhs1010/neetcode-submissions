class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        
        dp = [[0] * (amount+1) for _ in range(len(coins))]
        dp[0][0] = 1
        
        for i in range(len(coins)):
            for j in range(amount+1):
                if i-1 >= 0:
                    if j - coins[i] >= 0:
                       dp[i][j] += dp[i-1][j] + dp[i][j-coins[i]]
                    else:
                        dp[i][j] += dp[i-1][j]
                elif j - coins[i] >= 0:
                    dp[i][j] += dp[i][j-coins[i]]
                
                 #how do we take a set here
        
        return dp[len(coins)-1][amount]