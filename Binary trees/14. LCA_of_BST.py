# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        self.ans = None
        def helper(root):
            if not root:
                return
            # p and q is in left and right
            if p.val < root.val and root.val < q.val:
                self.ans = root
                return
            # p and q is in right and left
            if p.val > root.val and root.val > q.val:
                self.ans = root
                return
            # if p or q is root
            if p.val == root.val or q.val == root.val:
                self.ans = root
                return
            # if p and q is on left go left
            if p.val < root.val and q.val < root.val:
                helper(root.left)
            # if p and q is on right go right
            if p.val > root.val and q.val > root.val:
                helper(root.right)
        helper(root)
        return self.ans
        

        # smaller if el

        self.ans = None
        def helper(root):
            if not root:
                return
            # if p and q is on left go left
            elif p.val < root.val and q.val < root.val:
                helper(root.left)
            # if p and q is on right go right
            elif p.val > root.val and q.val > root.val:
                helper(root.right)
            else:
                self.ans = root
        helper(root)
        return self.ans