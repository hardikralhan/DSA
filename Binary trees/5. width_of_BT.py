
from collections import deque
class Solution(object):
    def widthOfBinaryTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        # 1. level order traversal
        # 2. indexation of every node (starting from 0 root)
        # 3. width = last_index - first_index + 1
        # 4. left -> 2*i , right -> 2*i+1
        
        if not root:
            return 0

        q = deque()
        q.append((root,0))
        width = 0
        while q:
            # width (last - first +1)
            # check case 3 to understand why max (if one node in the last)
            width = max(width, q[-1][1] - q[0][1] + 1)
            for _ in range(len(q)):
                node, index = q.popleft()
                if node.left:
                    q.append((node.left, 2*index))
                if node.right:
                    q.append((node.right, 2*index + 1))
        return width




        