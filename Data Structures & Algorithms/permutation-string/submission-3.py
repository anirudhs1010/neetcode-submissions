class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
 
        s1 = sorted(s1)
        l = 0
        r = 0
        while r <= len(s2):
            print(s2[l:r])
            if sorted(s2[l:r]) == s1:
                return True
            if r-l == (len(s1)):
                l += 1 
            r += 1
        return False