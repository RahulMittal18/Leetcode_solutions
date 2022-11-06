class Solution(object):
    def orderlyQueue(self, s, k):
        if k == 1:
            return min(s[i:] + s[:i] for i in range(len(s)))
        else:
            return ''.join(sorted(s))
        