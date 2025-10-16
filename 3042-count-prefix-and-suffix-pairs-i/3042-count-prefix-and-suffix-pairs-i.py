class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        cnt = 0
        n = len(words)
        for i in range(n):
            l = len(words[i])
            for j in range(i + 1,n):
                l2 = len(words[j])
                if(words[j][0:l] == words[i] and words[j][l2 - l:] == words[i]):
                    cnt += 1
        return cnt

