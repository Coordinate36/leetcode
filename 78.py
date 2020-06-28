class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = [[]]

        for num in nums:
            res += [cur + [num] for cur in res]
        return res
