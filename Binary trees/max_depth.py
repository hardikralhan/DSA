from collections import deque

def maxDepth(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
# level travesal solutiom
# will travel level by level and add the count of levels
        if not root:
            return 0
        q = deque()
        q.append(root)
        depth = 0
        while q:
            # for loop to calculate a level and store left right nodes
            for _ in range(len(q)):
                node = q.popleft()
                if node.left: 
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            depth = depth + 1
        return depth

# mathematical way ( 1 + max(left, right)) -> recursive way

        if not root:
            return 0
        
        return 1 + max(self.maxDepth(root.left),self.maxDepth(root.right))