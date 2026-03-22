def isSameTree(self, p, q):
        """
        :type p: Optional[TreeNode]
        :type q: Optional[TreeNode]
        :rtype: bool
        """
        if not p and not q:  # no node both sides
            return True
        if not p or not q:  # not a same tree (one node is extra to other)
            return False
        if p.val != q.val:
            return False
        
        # true and false = flase
        return self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right)