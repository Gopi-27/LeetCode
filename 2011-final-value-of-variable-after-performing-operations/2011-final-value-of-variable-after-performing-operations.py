class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        x = 0
        for s in operations:
            if ('X++' in s) or ('++X' in s):
                x += 1
            else :
                x -= 1
        return x