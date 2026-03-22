def maxPathSum(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        # global
        self.max_sum = float('-inf')

        def dfs(root):
            if not root:
                return 0
            
            # 1. go left then right 
            # 2. max sum = root.val + left sum + right sum
            # 3. return root val + max (left, right)

            # in case left or right is bringing negative back
            left_sum = max(0,dfs(root.left))
            right_sum = max(0,dfs(root.right))

            # stores the max value
            self.max_sum = max(self.max_sum, root.val + left_sum + right_sum)

            # returns the maximum path sum
            return root.val + max(left_sum,right_sum)

        dfs(root)
        return self.max_sum