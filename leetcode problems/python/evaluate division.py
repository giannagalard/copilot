# You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

# You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

# Return the answers to all queries. If a single answer cannot be determined, return -1.0.

# Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

class Solution(object):
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        # build the graph
        graph = collections.defaultdict(dict)
        for (x, y), v in zip(equations, values):
            graph[x][y] = v
            graph[y][x] = 1.0 / v
        # dfs
        def dfs(x, y, visited):
            if x not in graph or y not in graph:
                return -1.0
            if x == y:
                return 1.0
            visited.add(x)
            for n in graph[x]:
                if n not in visited:
                    ret = dfs(n, y, visited)
                    if ret != -1.0:
                        return ret * graph[x][n]
            return -1.0
        # query
        ret = []
        for x, y in queries:
            visited = set()
            ret.append(dfs(x, y, visited))
        return ret

# Time complexity : O(n^2)
# Space complexity : O(n)