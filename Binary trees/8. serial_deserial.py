class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return ""
        q = deque()
        q.append(root)
        res = []
        while q:
            node = q.popleft()
            if node:
                res.append(str(node.val))
                q.append(node.left)
                q.append(node.right)
            else:
                res.append("null")

        # ["1","2","3","null"] = "1,2,3,null"
        return ",".join(res)


    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if data == "":
            return None
        # "1,2,3,null" = ["1","2","3","null"]
        values = data.split(",")
        # get thr first root element
        root = TreeNode(int(values[0]))
        q = deque()
        q.append(root)

        # i (index) - keep track of elements of values array
        i = 1

        while q:
            # every node will add node for left and then right with help of i
            node = q.popleft()
            # going left
            if values[i] != "null":
                node.left = TreeNode(int(values[i]))
                q.append(node.left)
            i += 1
            
            # going right
            if values[i] != "null":
                node.right = TreeNode(int(values[i]))
                q.append(node.right)
            i += 1
        
        return root
            
