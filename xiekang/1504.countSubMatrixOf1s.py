# brute force
class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        res = 0

        for i in range(m):
            for j in range(0, n):
                if mat[i][j]:
                    # calculate the column pre-sums
                    if i > 0:
                        mat[i][j] = mat[i-1][j] + 1
                    k = j
                    minHeightRow = mat[i][j]
                    while k >= 0 and mat[i][k] != 0:
                        # calculate each column, how many this cell can contribute to
                        # note, it needs to keep at the lowest
                        # e.g. 3 1 2 --> then between height-3 and height-2.. the effective height is only 1
                        # this generize the current column too
                        minHeightRow = min(mat[i][j], mat[i][k], minHeightRow)
                        res += minHeightRow
                        k -= 1
        return res
      
      
# a little better with monotonoic stack
class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        res = 0

        for i in range(m):
            rowStack = []  # (val,idx)
            for j in range(0, n):
                if mat[i][j]:
                    # calculate the column pre-sums
                    if i > 0:
                        mat[i][j] = mat[i-1][j] + 1
                    idx = j
                    res += mat[i][j]
                    while rowStack and rowStack[-1][0] >= mat[i][j]:
                        _, _, idx = rowStack.pop()
                    res += mat[i][j] * (j-idx)

                    for val, origIdx, extendIdx in rowStack:
                        res += val * (origIdx-extendIdx+1)
                    rowStack.append((mat[i][j], j, idx))
                else:
                    rowStack = []
        return res
      
   
  # dp plus monotonic stack
class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        res = 0

        for i in range(m):
            rowStack = [(0, -1, 0)]  # (val,idx, dpSum)
            for j in range(0, n):
                if mat[i][j]:
                    myContri = 0
                    # calculate the column pre-sums
                    if i > 0:
                        mat[i][j] = mat[i-1][j] + 1
                    idx = j
                    # anything bigger equal than me
                    while rowStack and rowStack[-1][0] >= mat[i][j]:
                        rowStack.pop()
                    myContri += mat[i][j] * (j-rowStack[-1][1])
                    myContri += rowStack[-1][2]
                    rowStack.append((mat[i][j], j, myContri))
                    res += myContri

                else:
                    rowStack.append((0, j, 0))
        return res
