# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    
    def kthSmallest(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
        """
        self.count = 0
        self.ans = 0
        def helper(root):
            # inorder is always sprted in BST
            if not root:
                return

            # left node right
            helper(root.left)
            self.count += 1
            if self.count == k:
                self.ans = root.val
                return
            helper(root.right)

        helper(root)
        return self.ans

        