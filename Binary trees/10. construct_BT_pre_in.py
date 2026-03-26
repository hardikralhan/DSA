class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: Optional[TreeNode]
        """

        if not preorder or not inorder:
            return None

        # first el will always be root
        root_val = preorder.pop(0)
        root = TreeNode(root_val)
        # searching inorder for that root takes O(n)
        mid = inorder.index(root_val)

        # taking the help of mid - [1:mid+1] this also take O(n)
        root.left = self.buildTree(preorder, inorder[:mid])
        root.right = self.buildTree(preorder, inorder[mid+1:])

        return root
    
        # optimised way
        # hash map of inorder 


        # hashmap for O(1) index lookup
        inorder_map = {val: idx for idx, val in enumerate(inorder)}
        
        def helper(left,right):

            if left>right:
                return None

            root_val = preorder.pop(0)
            root = TreeNode(root_val)
            # searching inorder for that root takes O(n)
            mid = inorder_map[root_val]

            root.left = helper(left, mid-1)
            root.right = helper(mid+1, right)

            return root
        return helper(0,len(inorder) - 1)
    

