class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = {}
        for a in range(numCourses):
            adj[a] = []
        for a in prerequisites:
            adj[a[1]].append(a[0])
        print(adj)
        indegree = [0] * numCourses
        for a in adj.values():
            for j in a:
                indegree[j] += 1

        print(indegree)
        q = deque()
        for a in range(len(indegree)):
            if indegree[a] == 0:
                q.append(a)

        res = []
        while q:
            node = q.popleft()
            res.append(node)
            for a in adj[node]:
                indegree[a] -= 1
                if indegree[a] == 0:
                    q.append(a)
        print(res)
        if len(res) != numCourses:
            return []
        return res


        return []
