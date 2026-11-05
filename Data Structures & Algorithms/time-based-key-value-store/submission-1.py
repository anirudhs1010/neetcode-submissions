class TimeMap:

    def __init__(self):
        self.m = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key in self.m :
            self.m[key].append((value, timestamp))
        else:
            self.m[key] = [(value, timestamp)]

    def get(self, key: str, timestamp: int) -> str:
        #largest timestamp value here so we need a val of greatest min or equal
        #could use heap or binary search an array
        if key not in self.m:
            return ""
        h = self.m[key]
        l, r = 0, len(h) - 1
        res = ""
        while l <= r:
            mid = (l +r)//2
            v, t = h[mid]
            if t <= timestamp:
                res = v
                l = mid+1
            else:
                r = mid - 1
            
        return str(res)