class Solution:
    
    def permute(self, nums: List[int]) -> List[List[int]]:
        seen = set()
        ans = []
        def dfs(i, v):
            if len(v) == len(nums):
                ans.append(v.copy())
                return
            for j in range(0, len(nums)):
                if j not in seen:
                    seen.add(j)
                    v.append(nums[j])
                    dfs(j+1, v) 
                    v.pop()
                    seen.remove(j)
        dfs(0, [])
        return ans