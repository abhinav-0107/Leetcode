class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        def getMaxCons(ansToChange):
            maxCons = 1
            numAnsToChange = 0
            p1 = 0
            for p2 in range(len(answerKey)):
                if answerKey[p2] == ansToChange:
                    numAnsToChange += 1
                    while numAnsToChange > k:
                        if answerKey[p1] == ansToChange:
                            numAnsToChange -= 1
                        p1 += 1
                maxCons = max(maxCons, p2-p1+1)
            return maxCons

        return max(getMaxCons('F'), getMaxCons('T'))
    