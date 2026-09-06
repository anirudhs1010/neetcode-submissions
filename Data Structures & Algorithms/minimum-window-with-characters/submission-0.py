class Solution:
    def minWindow(self, s: str, t: str) -> str:
        l, r = 0, 0
        f = Counter(t)
        sz = len(f.keys())
        cnt = 0
        formed = {}
        mins = float('inf')
        finalL, finalR = 0, 0
        while r < len(s):
            if s[r] in formed:
                formed[s[r]] += 1
            else:
                formed[s[r]] = 1
            if s[r] in f and f[s[r]] == formed[s[r]]:
                cnt += 1
            r += 1
            while cnt == sz:
                if mins > r-l:
                    finalL = l
                    finalR = r
                    mins = r-l
                
                
                if s[l] in f:
                    if formed[s[l]] == f[s[l]]:
                        cnt -= 1
                    formed[s[l]] -= 1
                l += 1
            
            
            
        return s[finalL:finalR]