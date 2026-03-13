class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(10)

    #         1
    #     2       3
    #  4    5   10    


# DFS 
# preorder traversal recursive
# root left right

def preorder(Node):
    if not Node:
        return

    print(Node.val)
    preorder(Node.left)
    preorder(Node.right)

preorder(root)

print("====================")

# inorder traversal recursive
# left root right

def inorder(Node):
    if not Node:
        return

    inorder(Node.left)
    print(Node.val)
    inorder(Node.right)

inorder(root)

print("====================")

# postorder traversal recursive
# left right root 

def postorder(Node):
    if not Node:
        return

    postorder(Node.left)
    postorder(Node.right)
    print(Node.val)

postorder(root)


print("=== pre order travesal with stack")

def preorder_stack(node):
    stk = [node]
    while stk:
        node = stk.pop() #getting the top element
        print(node.val)
        if node.right:
            stk.append(node.right)
        if node.left: 
            stk.append(node.left)

print(preorder_stack(root))


# level order traversal using a dequeue (BFS)

print("=========== BFS queue")

from collections import deque

def bfs_dequeue(node):
    q = deque()
    q.append(node)
    while q:
        node = q.popleft()
        print(node.val)
        if node.left:
            q.append(node.left)
        if node.right:
            q.append(node.right)

bfs_dequeue(root)


print("=========== search DFS")
# check if value exists (search)
# DFS
def search(node, target):
    if not node:           # this condition will come first
        return False
    
    if node.val == target:
        return True

    # true or false is true
    return search(node.left, target) or search(node.right, target)

print(search(root, 10))


# if a binary search tree
# current node is not BST, this is just psydo code
def search_bst(node, target):
    if not node:
        return False
    if node.val == target:
        return True
    
    if target < node.val: 
        return search_bst(node.left, target)
    else:
        return search_bst(node.right, target)
    

            

        
