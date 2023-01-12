class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        # 1. calculate the prefix sum - O(n)
        # we need to translate this problem into finding the pair-(i,j)
        # sum(i,j) = sum(j) - sum(i-1)
        # e.g. the sum(1,1) = sums[1] - sums[0] -> the sum of first element 
        # sum(1,3) = sums[3] - sums[0] -> the sum of first 3 elements 
        sums = [0] * (len(nums)+1)
        for i,n in enumerate(nums):
            sums[i+1] = sums[i] + n

        # 2. in that sums array, we search pairs of i,j where
        #  sum(i,j) in [lower, upper]
        #  or say  lower <= sums[j] - sums[i-1] <= upper 
        #  two variables make it pretty difficult to reason about so transform
        #  fix i, finding j where sums[i-1] + lower <= sums[j] <= sums[i-1] + upper 
        # notice this is logicall i-1 and j pair, but a pair of (i-1,j) is just a pair of (i,j)
        # let me see 
        def pairs(i,j):
            if i>j:
                return 0 
            if i == j:
                return 1 if  lower<= sums[j] - sums[i-1]<=upper else 0
            
            m = i+(j-i)//2
            # divide and conquer 
            leftPairs = pairs(i,m)
            rightPairs = pairs(m+1,j)

            # cross over the m
            # fix left side, finding the range in the right side that fits sums[i-1] + lower <= sums[j] <= sums[i-1] + upper
            # sums[i-1] + lower <= sums[j] <= sums[i-1] + upper
            crossPairs = 0
            for l in range(i, m+1):
                # searching for upper-bound? lower-bound? of sums[l-1]+upper
                # yeah, upper bound.. the first number that is > "sums[l-1]+upper"
                y = bisect.bisect_right(sums, sums[l-1]+upper, lo=m+1, hi=j+1) - (m+1)
                # searching for lower-bound
                x = bisect.bisect_left(sums, sums[l-1]+lower, lo=m+1, hi=j+1) - (m+1)
                crossPairs += y-x
            
            # so that merge sort naturally has some relationship to divide and conquer
            # and here we need to borrow the idea of merge sort
            # before return we need to sort 
            temp = []

            l, r = i,m+1
            while l < m+1 and r < j+1:
                if sums[l] < sums[r]:
                    temp.append(sums[l])
                    l += 1
                else:
                    temp.append(sums[r])
                    r += 1
            if l<m+1:
                temp.extend(sums[l:m+1])
            else:
                temp.extend(sums[r:j+1])
            sums[i:j+1] = temp
            return leftPairs + crossPairs + rightPairs

        return pairs(1,len(nums))
