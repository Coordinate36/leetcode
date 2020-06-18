import collections

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        ans = []
        deq = collections.deque()
        deq.append(root)
        while deq:
            node = deq.popleft()
            if node is None:
                ans.append('n')
                continue
            ans.append(str(node.val))
            deq.append(node.left)
            deq.append(node.right)

        return ' '.join(ans)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        elems = data.split(' ')
        deq = collections.deque()
        root = None if elems[0] == 'n' else TreeNode(int(elems[0]))
        deq.append(root)
        idx = 1
        while deq:
            node = deq.popleft()
            if node is None:
                continue
            node.left = None if elems[idx] == 'n' else TreeNode(int(elems[idx]))
            node.right = None if elems[idx+1] == 'n' else TreeNode(int(elems[idx+1]))
            deq.append(node.left)
            deq.append(node.right)
            idx += 2
        return root

# Your Codec object will be instantiated and called as such:
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
codec = Codec()
print(codec.deserialize(codec.serialize(root)).left.val)