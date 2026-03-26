# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: Optional[TreeNode]
        """
        # brute
        if not inorder:
            return None
        
        root_val = postorder.pop()
        root = TreeNode(root_val)
        # find mid
        mid = inorder.index(root_val)

        root.right = self.buildTree(inorder[mid+1:], postorder)
        root.right = self.buildTree(inorder[:mid], postorder)
        return root


        # optimised
        inorder_map = {val : idx for idx, val in enumerate(inorder)}

        def helper(left,right):

            if left > right:
                return None
            
            # takes the last el
            root_val = postorder.pop()
            root = TreeNode(root_val)
            # find mid
            mid = inorder_map[root_val]
            # go right and then left
            root.right = helper(mid + 1, right)
            root.left = helper(left, mid - 1)
            return root
        
        return helper(0, len(inorder) - 1)