def invertTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        if not root:
            return root # return None if nothing
        
        # swap both left and right
        root.left, root.right = root.right, root.left

        # go left and right
        self.invertTree(root.left)
        self.invertTree(root.right)
