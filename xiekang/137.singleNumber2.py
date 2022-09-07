class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for i in range(32):
            S = 0
            for n in nums:
                S += n>>i & 1
            S%=3
            if S:
                ans |= 1<<i
        
        return ans if not (ans >> 31) & 1 else -((~ans + 1) & 0xffffffff)

      
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # k=3, mask=~(x2&x1)  
        x1=x2=mask=0
        for n in nums:
            x2 ^= x1&n
            x1 ^= n
            mask = ~(x2&x1)
            x2&=mask
            x1&=mask
        
        return x1|x2
  
