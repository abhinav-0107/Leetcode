class Solution:
    def numberOfGoodPaths(self, vals: List[int], edges: List[List[int]]) -> int:
        n = len(vals)
        p = list(range(n))
        count = [Counter({vals[i]:1}) for i in range(n)]
        edges = sorted((max(vals[i],vals[j]),i,j) for i,j in edges)
        res = n
        def find(i):
            if p[i] != i:p[i] = find(p[i])
            return p[i]
        for val, i, j in edges:
            pi, pj = find(i), find(j)
            res += count[pi][val]*count[pj][val]
            p[pi] = pj
            count[pj][val] += count[pi][val]
        return res
