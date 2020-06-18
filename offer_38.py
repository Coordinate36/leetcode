class Solution(object):
    def permutation(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        path = list(s)
        ans = []
        def dfs(x):
            if x == len(path) - 1:
                ans.append(''.join(path))
                return
            dic = set()
            for i in range(x, len(path)):
                if path[i] in dic:
                    continue
                dic.add(path[i])
                path[x], path[i] = path[i], path[x]
                dfs(x + 1)
                path[i], path[x] = path[x], path[i]
        dfs(0)
        return ans
