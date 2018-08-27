class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        return self._wordBreak(s, set(wordDict), 0, set())

    def _wordBreak(self, s, wordSet, start, visit):
        if start == len(s):
            return True
        if start in visit:
            return False
        
        for i in xrange(start + 1, len(s) + 1):
            sub = s[start:i]
            if sub in wordSet and self._wordBreak(s, wordSet, i, visit):
                return True

        visit.add(start)
        return False
            