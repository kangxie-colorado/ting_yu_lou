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
            while curr and n > 0:
                curr = curr.right if m & mask else curr.left
                n -= 1
                mask >>= 1

            return curr is not None

        l, r = 0, 50000
        while l < r:
            m = r-(r-l)//2
            if isNodeThere(m):
                l = m
            else:
                r = m-1
        return l

