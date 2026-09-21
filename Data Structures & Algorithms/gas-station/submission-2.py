class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas) < sum(cost):
            return -1
        curr = 0
        ans = 0
        n = len(gas)
        for i in range(n):
            curr += gas[i]
            curr -= cost[i]
            if curr < 0: # if we go negative, there's a get out of jail free card, but can only use this once.
                curr = 0
                ans = i+1
        return ans