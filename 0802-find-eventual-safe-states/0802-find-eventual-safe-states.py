class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n=len(graph)
        safe={}
        ans=[]
        def dfs(i):
            if i in safe:
                return safe[i]

            safe[i]=False
            for nei in graph[i]:
                if not dfs(nei):
                    return safe[i]

            safe[i]=True
            return safe[i]

        for i in range(n):
            if dfs(i):
                ans.append(i)

        return ans 