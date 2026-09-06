class Solution:
    def trap(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        area = 0
        lmax, rmax = 0, 0
        while l < r:
            lmax = max(lmax, height[l])
            rmax = max(rmax, height[r])
            if lmax < rmax:
                area += lmax - height[l]
                l += 1
            else:
                area += rmax - height[r]
                r -= 1
        return area