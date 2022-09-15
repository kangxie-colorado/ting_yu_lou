class Solution:
    def longestMountain(self, A: List[int]) -> int:
        res = 0
        i = 0

        while i < len(A)-1:
            j = i+1
            while j < len(A) and A[j] > A[j-1]:
                # increasing seq
                # end when A[j] <= A[j-1]
                j += 1
            if j == len(A):
                break

            if j > i+1:
                while j < len(A) and A[j] < A[j-1]:
                    # decreasing seq
                    # end when A[k] >= A[k-1]
                    j += 1

                    res = max(res, j-i)
            i = max(i+1, j-1)
        return res
   
  
  class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        res = 0
        i = 1

        while i < len(arr)-1:

            j1, j2 = i, i-1
            k1, k2 = i, i+1

            isMountain = False
            while j2 >= 0 and arr[j1] > arr[j2] and k2 < len(arr) and arr[k1] > arr[k2]:
                j1, j2 = j1-1, j2-1
                k1, k2 = k1+1, k2+1
                isMountain = True

            if isMountain:
                while j2 >= 0 and arr[j1] > arr[j2]:
                    j1, j2 = j1-1, j2-1

                while k2 < len(arr) and arr[k1] > arr[k2]:
                    k1, k2 = k1+1, k2+1

                res = max(res, k1-j1+1)
            i = max(k1,i+1)
        return res
      
      
class Solution:
    def longestMountain(self, A):
        res = up = down = 0
        for i in range(1, len(A)):
            if down and A[i - 1] < A[i] or A[i - 1] == A[i]: up = down = 0
            up += A[i - 1] < A[i]
            down += A[i - 1] > A[i]
            if up and down: res = max(res, up + down + 1)
        return res 
