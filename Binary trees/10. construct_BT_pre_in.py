class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: Optional[TreeNode]
        """

        # brute force O(n^2)
        if not preorder or not inorder:
            return None

        # first el will always be root
        root = TreeNode(preorder[0])
        # searching inorder for that root takes O(n)
        mid = inorder.index(preorder[0])

        # taking the help of mid - [1:mid+1] this also take O(n)
        root.left = self.buildTree(preorder[1:mid+1], inorder[:mid])
        root.right = self.buildTree(preorder[mid+1:], inorder[mid+1:])

        return root
    
        # optimised way
        # hash map of inorder 


        # hashmap for O(1) index lookup
        inorder_map = {val: idx for idx, val in enumerate(inorder)}
        
        self.pre_index = 0
        
        def helper(left, right):
            if left > right:
                return None
            
            # pick root from preorder
            root_val = preorder[self.pre_index]
            self.pre_index += 1
            
            root = TreeNode(root_val)
            
            # split inorder
            mid = inorder_map[root_val]
            
            # build left and right subtree
            root.left = helper(left, mid - 1)
            root.right = helper(mid + 1, right)
            
            return root
        
        return helper(0, len(inorder) - 1)
    

