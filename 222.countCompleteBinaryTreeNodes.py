class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        def isNodeThere(m):
            # decide the highest bit first
            n = 0
            while n < 16:  # 2**16 = 65536
                if 2**n <= m < 2**(n+1):
                    break
                n += 1

            if n == 0:
                return root is not None
            mask = 1 << (n-1)
            curr = root
            while n > 0:
                curr = curr.right if m & mask else curr.left
                if curr is None:
                    return False
                n -= 1
                mask >>= 1

            return True

        l, r = 0, 50000
        while l < r:
            m = r-(r-l)//2
            if isNodeThere(m):
                l = m
            else:
                r = m-1
        return l

    # another solution but kind of werid, not binary search at all
    class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        def helper(root):
            curr = root
            rightDepth = 0
            while curr:
                rightDepth += 1
                curr = curr.right

            curr = root
            leftDepth = 0
            while curr:
                leftDepth += 1
                curr = curr.left

            if leftDepth == rightDepth:
                return 2**leftDepth-1
            else:
                return 1 + helper(root.left) + helper(root.right)
        return helper(root)

