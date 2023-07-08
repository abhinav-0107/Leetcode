class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        # list of "dividers"
        v = []
        n = len(weights)
        
        for i in range(n-1):
            v.append(weights[i] + weights[i+1])
        
        v.sort()

        return sum(v[n-k:]) - sum(v[:k-1])