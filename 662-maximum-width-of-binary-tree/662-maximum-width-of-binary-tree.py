'''
For node at i'th position position of node.left will be 2*i 
and  node.right will be 2*i + 1. We traverse through the tree
and assign position to nodes. Width of a level is difference of 
positions between the leftmost and rightmost nodes in that level.
'''
class Solution(object):
    def widthOfBinaryTree(self, root):
        if not root: return 0
        q = [(root, 1)]
        ans = 1  # because cases like [1], [1,3] etc. has width 1
        while q:            
		# first element in q is leftmost element in that level and
		# last element is rightmost element
		# the difference in their position is the width of that level
            if len(q) >= 2:
                ans = max(q[-1][1] - q[0][1] + 1, ans)
            new_q = []          # this stores nodes for next level  
            while q:
                node, pos = q.pop(0)                      
                if node.left: new_q.append((node.left, 2*pos))
                if node.right: new_q.append((node.right, 2*pos + 1))            
            q = new_q
        return ans