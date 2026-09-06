class Solution:
    
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        def backtrack(v, i):
            if i == len(nums):
                ans.append(v.copy())
                return
            v.append(nums[i])
            backtrack(v, i+1)
            v.pop()
            backtrack(v, i+1)
        backtrack([], 0)
        return ans
