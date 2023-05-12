from typing import List
class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        dp = [0] * (n+1)
        for i in range(n-1, -1, -1):
            point = questions[i][0]
            jump = questions[i][1]

            nextQuestion = min(n, i+jump+1)
            dp[i] = max(dp[i+1], point + dp[nextQuestion])
        return dp[0]