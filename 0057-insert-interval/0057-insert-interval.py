class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        heap, ans, = [], [] 
        for s, e in intervals + [newInterval]: # add start & end to heap (-1 is start, 1 is end)
            heapq.heappush(heap, (s, -1))
            heapq.heappush(heap, (e, 1))
        cur, s = 0, None            
        while heap:                            
            i, val = heapq.heappop(heap)       # pop heap
            if s is None: s = i                # is s is None, assign i to s (interval start)
            cur += val                         # keep counting until close interval
            if not cur:                        # when cur == 0, meaning we can close the interval
                ans.append([s, i])             # append interval to ans
                s = None                       # reset s to None
        return ans 