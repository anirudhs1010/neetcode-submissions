class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = sum(nums)
        if n % 2 != 0:
            return False
        ans = n // 2
        dp = [False] * (ans + 1)
        dp[0] = True
        for i in range(len(nums)):
            for j in range(ans, nums[i] - 1, -1):
                dp[j] = dp[j] or dp[j-nums[i]]
        return dp[ans]