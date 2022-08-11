# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidBST(self, root, minm = float("-inf"), maxm = float("inf")):
            return (not root) or (minm <root.val<maxm and (self.isValidBST(root.left, minm, root.val)) and (self.isValidBST(root.right, root.val, maxm)))