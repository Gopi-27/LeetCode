class Solution:
    
    def numberOfBeams(self, bank: List[str]) -> int:
        prevOnes = 0
        totalLasers = 0
        for s in bank:
            curOnes = s.count('1')
            totalLasers += prevOnes * curOnes
            if curOnes :
                prevOnes = curOnes
        return totalLasers
    