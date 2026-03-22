# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSubtree(self, root, subRoot):
        """
        :type root: Optional[TreeNode]
        :type subRoot: Optional[TreeNode]
        :rtype: bool
        """
        # start comparing with subRoot
        if not root:
            return False
        # there can be duplicate values so keep on recursing
        if root.val == subRoot.val:
            trueValue = self.dfs(root,subRoot)
            if trueValue:
                return True
        left = self.isSubtree(root.left, subRoot)
        right = self.isSubtree(root.right, subRoot)
        return left or right
        

    def dfs(self,root,subRoot):
        if not root and not subRoot:
            return True
        if not root or not subRoot:
            return False
        if root.val != subRoot.val:
            return False
        left = self.dfs(root.left,subRoot.left)
        right = self.dfs(root.right,subRoot.right)
        return left and right

        