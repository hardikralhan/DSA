from collections import deque
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """
        if not root:
            return []
        q = deque()
        q.append(root)
        list2 = []
        while q:
            list1 = []
            # process only those nodes that are in that level
            for _ in range(len(q)):
                node = q.popleft()
                list1.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            list2.append(list1)

        return list2