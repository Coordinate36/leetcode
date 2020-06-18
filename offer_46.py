class Solution(object):
    def translateNum(self, num):
        """
        :type num: int
        :rtype: int
        """
        num = str(num)
        dp = [0] * (len(num) + 1)
        dp[0] = 1
        dp[1] = 1
        for i in range(2, len(dp)):
            dp[i] = dp[i-1]
            if num[i-2] == '1' or (num[i-2] == '2' and num[i-1] < '6'):
                dp[i] += dp[i-2]
        return dp[len(num)]
