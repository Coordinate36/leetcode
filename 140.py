class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        if not wordDict:
            return []
        wordSet = set(wordDict)
        maxWordLen = max(len(word) for word in wordSet)
        mem = {}
        def _wordBreak(s):
            if s in mem:
                return mem[s]
            ans = []
            if s in wordSet:
                ans.append(s)
            for i in range(1, min(maxWordLen + 1, len(s))):
                left = s[:i]
                if left in wordSet:
                    ans += [left + ' ' + w for w in _wordBreak(s[i:])]
            mem[s] = ans
            return ans
        return _wordBreak(s)


solution = Solution()
print solution.wordBreak("catsanddog", ["cat","cats","and","sand","dog"])