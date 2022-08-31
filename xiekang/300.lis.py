class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        lis = [nums[0]]
        for n in nums[1:]:
            if n < lis[0]:
                lis[0] = n
            elif n > lis[-1]:
                lis.append(n)
            else:
                idx = bisect.bisect_left(lis, n)
                lis[idx] = n

        return len(lis)
