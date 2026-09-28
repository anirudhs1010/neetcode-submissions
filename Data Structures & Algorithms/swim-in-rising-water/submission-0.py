class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        #adjust weights
        #how do I even modify shortest path here
        n = len(grid)
        m = len(grid[0])
        heap = [(grid[0][0], 0, 0)]
        vis = {(0, 0)}
        dirs = [(0,1), (1, 0), (0, -1), (-1, 0)]
        while heap:
            e, r, c = heapq.heappop(heap)
            if r == n-1 and c == n-1:
                return e
            for dr, dc in dirs:
                nr, nc = r+dr, c+dc
                if (nr, nc) in vis:
                    continue

                if 0 <= nr < m and 0 <= nc < n:
                    vis.add((nr, nc))
                    # The new time is the max of the current path's max time and the new cell's elevation
                    heapq.heappush(heap, (max(e, grid[nr][nc]), nr, nc))
                    