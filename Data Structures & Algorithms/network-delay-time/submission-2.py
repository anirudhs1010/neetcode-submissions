class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        edges = defaultdict(list)
        for u, v, w in times:
            edges[u].append((v, w))
        
        min_heap = [(0, k)]
        vis = set()
        t = 0
        while min_heap:
            w1, n1 = heapq.heappop(min_heap)
            if n1 in vis:
                continue
            vis.add(n1)
            t = max(t, w1)
            for au, aw in edges[n1]:
                heapq.heappush(min_heap, (aw + w1, au))
            
        return t if len(vis) == n else -1
