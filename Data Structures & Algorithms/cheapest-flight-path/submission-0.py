class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        #first we create an adjacency list
        #then check for stops and q
        #while looping through the q check adj[neighbor]
        #check if the price+cost < dist[neighbor] (shortest path)
        #then append this to the q if so
        #return dist[dst]
        adj = {i : [] for i in range(n)}
        for u, v, price in flights:
            adj[u].append((v, price))
        dist = [float('inf')]*n
        q = deque([(src, 0)])
        stops = 0
        while q and stops <= k:
            for _ in range(len(q)):
                node, cost = q.popleft()
                for neighbor, price in adj[node]:
                    if price+cost < dist[neighbor]:
                        dist[neighbor] = price+cost
                        q.append((neighbor, dist[neighbor]))
            stops += 1
        return dist[dst] if dist[dst] != float('inf') else -1